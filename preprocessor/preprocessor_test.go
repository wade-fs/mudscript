package preprocessor

import (
	"os"
	"path/filepath"
	"strings"
	"testing"
)

func TestIncludeOverlayPrecedence(t *testing.T) {
	root := t.TempDir()
	commonDir := filepath.Join(root, "common")
	worldDir := filepath.Join(root, "world")

	for _, d := range []string{
		filepath.Join(commonDir, "include"),
		filepath.Join(commonDir, "std"),
		filepath.Join(worldDir, "include"),
	} {
		if err := os.MkdirAll(d, 0755); err != nil {
			t.Fatalf("mkdir %s: %v", d, err)
		}
	}

	os.WriteFile(filepath.Join(commonDir, "include", "config.h"), []byte("#define WORLD_TAG \"common_cfg\"\n"), 0644)
	os.WriteFile(filepath.Join(worldDir, "include", "config.h"), []byte("#define WORLD_TAG \"world_cfg\"\n"), 0644)
	os.WriteFile(filepath.Join(commonDir, "include", "shared.h"), []byte("#define SHARED_VAL 42\n"), 0644)
	os.WriteFile(filepath.Join(commonDir, "std", "local.h"), []byte("#define LOCAL_VAL 99\n"), 0644)

	pp := New(worldDir)
	pp.SetCommonPath(commonDir)

	src := `
#include <config.h>
#include <shared.h>
#include "local.h"
string tag = WORLD_TAG;
int a = SHARED_VAL;
int b = LOCAL_VAL;
`
	out, err := pp.Process("/std/test.c", src)
	if err != nil {
		t.Fatalf("Process failed: %v", err)
	}
	if !strings.Contains(out, `"world_cfg"`) {
		t.Fatalf("expected world include override, got:\n%s", out)
	}
	if !strings.Contains(out, "int a = 42;") {
		t.Fatalf("expected common include fallback for shared.h, got:\n%s", out)
	}
	if !strings.Contains(out, "int b = 99;") {
		t.Fatalf("expected common relative include fallback for local.h, got:\n%s", out)
	}
}

func TestIncludeChrootViolation(t *testing.T) {
	root := t.TempDir()
	commonDir := filepath.Join(root, "common")
	worldDir := filepath.Join(root, "world")
	os.MkdirAll(filepath.Join(commonDir, "include"), 0755)
	os.MkdirAll(filepath.Join(worldDir, "include"), 0755)
	os.WriteFile(filepath.Join(root, "outside.h"), []byte("#define SECRET 1\n"), 0644)

	pp := New(worldDir)
	pp.SetCommonPath(commonDir)

	if _, err := pp.Process("/std/bad.c", "#include \"../../outside.h\"\n"); err == nil {
		t.Fatalf("expected chroot violation error for ../../outside.h")
	}
}
