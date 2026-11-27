import re, os, sys, collections
root = sys.argv[1]
files = []
for dp, dn, fn in os.walk(root):
    for f in fn:
        if f.endswith(('.c','.h')):
            files.append(os.path.join(dp, f))
src = {}
for p in files:
    try: src[p] = open(p, encoding='utf-8', errors='replace').read()
    except: pass
rel = lambda p: '/' + os.path.relpath(p, root)

# 1. referenced paths exist
pathre = re.compile(r'"(/(?:d|clone|std|item|npc|daemon|secure|cmds|area|include)/[A-Za-z0-9_/\.\-]+)"')
missing = collections.defaultdict(set)
allf = {rel(p) for p in files}
for p, s in src.items():
    for m in pathre.finditer(s):
        t = m.group(1)
        cand = t if t.endswith(('.c','.h')) else t + '.c'
        if cand not in allf and not os.path.exists(root + cand) and not os.path.isdir(root + t):
            missing[t].add(rel(p))
print("== 1. 被引用但不存在的路徑 ==")
for t, users in sorted(missing.items()):
    print(f"  {t}  <- {', '.join(sorted(users))[:100]}")

# 2. function defs vs ->call(
defre = re.compile(r'^\s*(?:static\s+|private\s+|nomask\s+|varargs\s+)*(?:int|void|string|object|mixed|mapping|float|object\s*\*|string\s*\*|int\s*\*|mixed\s*\*)\s*\**\s*([A-Za-z_]\w*)\s*\(', re.M)
defs = collections.defaultdict(set)
for p, s in src.items():
    for m in defre.finditer(s):
        defs[m.group(1)].add(rel(p))
callre = re.compile(r'->\s*([A-Za-z_]\w*)\s*\(')
calls = collections.defaultdict(set)
for p, s in src.items():
    s2 = re.sub(r'//.*','',s)
    for m in callre.finditer(s2):
        calls[m.group(1)].add(rel(p))
print("\n== 2. 被 -> 呼叫、但全專案沒有任何定義的函式 ==")
for n, users in sorted(calls.items()):
    if n not in defs:
        print(f"  {n}()  <- {', '.join(sorted(users))[:110]}")
