#!/usr/bin/env bash
set -euo pipefail

K8S_DOCKER_IMAGE="${K8S_DOCKER_IMAGE:-wadefs/forgotten-space:latest}"
K8S_DIR="${K8S_DIR:-$HOME/src/Simba/k8s}"
K8S_MANIFEST="${K8S_MANIFEST:-tenants/wade/mud.yaml}"
MUD_COMMIT="${MUD_COMMIT:-$(git rev-parse --short=8 HEAD)}"

IMAGE_REPO="${K8S_DOCKER_IMAGE%%@*}"
IMAGE_REPO="${IMAGE_REPO%:*}"

echo "🔍 Resolving image digest for ${K8S_DOCKER_IMAGE}..."
DIGEST=""
if command -v docker >/dev/null 2>&1; then
    DIGEST="$(docker buildx imagetools inspect "${K8S_DOCKER_IMAGE}" 2>/dev/null | awk '/^Digest:[[:space:]]*sha256:/ {print $2; exit}' || true)"
    if [ -z "${DIGEST}" ]; then
        DIGEST="$(docker inspect --format='{{range .RepoDigests}}{{println .}}{{end}}' "${K8S_DOCKER_IMAGE}" 2>/dev/null | awk -v repo="${IMAGE_REPO}" '$0 ~ "^" repo "@sha256:" {sub(/^.*@/, ""); print; exit}' || true)"
    fi
fi

if [[ ! "${DIGEST}" =~ ^sha256:[0-9a-f]{64}$ ]]; then
    echo "❌ Failed to resolve valid sha256 digest for ${K8S_DOCKER_IMAGE} (got: '${DIGEST}')" >&2
    exit 1
fi
echo "✅ Image digest: ${IMAGE_REPO}@${DIGEST}"

if [ ! -d "${K8S_DIR}/.git" ]; then
    echo "❌ K8S_DIR is not a git repository: ${K8S_DIR}" >&2
    exit 1
fi

if [ -n "$(git -C "${K8S_DIR}" status --porcelain)" ]; then
    echo "❌ ${K8S_DIR} has uncommitted changes; please commit or stash them first." >&2
    exit 1
fi

ORIG_BRANCH="$(git -C "${K8S_DIR}" rev-parse --abbrev-ref HEAD)"
BRANCH="k8s-mud-${MUD_COMMIT}-$(date +%Y%m%d%H%M%S)"
CREATED_BRANCH=""

cleanup() {
    local rc=$?
    git -C "${K8S_DIR}" checkout -q "${ORIG_BRANCH}" 2>/dev/null || true
    if [ "${rc}" -ne 0 ] && [ -n "${CREATED_BRANCH}" ]; then
        git -C "${K8S_DIR}" branch -D "${CREATED_BRANCH}" 2>/dev/null || true
    fi
}
trap cleanup EXIT

echo "🔄 Fetching origin/main in ${K8S_DIR}..."
git -C "${K8S_DIR}" fetch origin main
git -C "${K8S_DIR}" checkout -q -b "${BRANCH}" origin/main
CREATED_BRANCH="${BRANCH}"

MANIFEST_PATH="${K8S_DIR}/${K8S_MANIFEST}"
if [ ! -f "${MANIFEST_PATH}" ]; then
    echo "❌ Manifest not found: ${MANIFEST_PATH}" >&2
    exit 1
fi

echo "📝 Updating ${K8S_MANIFEST} with ${IMAGE_REPO}@${DIGEST}..."
python3 - "${MANIFEST_PATH}" "${IMAGE_REPO}" "${DIGEST}" <<'PY'
import re
import sys
from pathlib import Path

manifest = Path(sys.argv[1])
repo = sys.argv[2]
digest = sys.argv[3]

text = manifest.read_text(encoding="utf-8")
pattern = re.compile(rf"(\bimage:\s*){re.escape(repo)}(?:@sha256:[0-9a-f]{{64}}|:[^\s#]+)?")
new_text, count = pattern.subn(rf"\g<1>{repo}@{digest}", text)
if count == 0:
    print(f"No matching image entry for {repo} in {manifest}", file=sys.stderr)
    sys.exit(1)

manifest.write_text(new_text, encoding="utf-8")
print(f"Updated {count} image reference(s) in {manifest}")
PY

if git -C "${K8S_DIR}" diff --quiet "${K8S_MANIFEST}"; then
    echo "ℹ️  ${K8S_MANIFEST} already uses ${IMAGE_REPO}@${DIGEST}; no PR needed."
    exit 0
fi

git -C "${K8S_DIR}" add "${K8S_MANIFEST}"
git -C "${K8S_DIR}" commit -m "chore(mud): update forgotten-space image (${MUD_COMMIT})"

echo "📤 Pushing branch ${BRANCH} to origin..."
git -C "${K8S_DIR}" push -u origin "${BRANCH}"

FETCH_URL="$(git -C "${K8S_DIR}" remote get-url origin)"
PUSH_URL="$(git -C "${K8S_DIR}" remote get-url --push origin)"

echo "🔀 Opening pull request on Forgejo..."
python3 - "${FETCH_URL}" "${PUSH_URL}" "${BRANCH}" "${MUD_COMMIT}" "${IMAGE_REPO}@${DIGEST}" <<'PY'
import json
import os
import sys
from urllib.error import HTTPError
from urllib.parse import urlsplit
from urllib.request import Request, urlopen

fetch_url, push_url, branch, commit, image_ref = sys.argv[1:6]

def parse_remote(url: str):
    parts = urlsplit(url)
    path = parts.path.strip("/")
    if path.endswith(".git"):
        path = path[:-4]
    server = f"{parts.scheme}://{parts.hostname}"
    if parts.port:
        server += f":{parts.port}"
    return server, path, parts.username, parts.password

server, upstream_repo, _, fetch_pass = parse_remote(fetch_url)
_, push_repo, push_user, push_pass = parse_remote(push_url)

fork_owner = push_repo.split("/", 1)[0] if "/" in push_repo else (push_user or "")
token = os.environ.get("FORGEJO_TOKEN") or push_pass or fetch_pass
if not token:
    print("❌ Missing Forgejo token (set FORGEJO_TOKEN or include token in git remote URL)", file=sys.stderr)
    sys.exit(1)

head = f"{fork_owner}:{branch}" if fork_owner and fork_owner != upstream_repo.split("/", 1)[0] else branch
payload = {
    "title": f"chore(mud): update forgotten-space image ({commit})",
    "head": head,
    "base": "main",
    "body": f"Update `{image_ref}` from `mudscript` commit `{commit}`.",
}

req = Request(
    f"{server}/api/v1/repos/{upstream_repo}/pulls",
    method="POST",
    data=json.dumps(payload).encode("utf-8"),
    headers={
        "Authorization": f"token {token}",
        "Content-Type": "application/json",
        "Accept": "application/json",
    },
)
try:
    with urlopen(req, timeout=30) as resp:
        pr = json.loads(resp.read().decode("utf-8"))
        print(f"✅ PR #{pr['number']} created: {pr['html_url']}")
except HTTPError as exc:
    body = exc.read().decode("utf-8", errors="replace")
    print(f"❌ Forgejo API error (HTTP {exc.code}): {body}", file=sys.stderr)
    sys.exit(1)
PY

if [ "${ORIG_BRANCH}" = "main" ]; then
    git -C "${K8S_DIR}" checkout -q main
    git -C "${K8S_DIR}" merge --ff-only origin/main >/dev/null 2>&1 || true
fi
