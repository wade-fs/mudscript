package driver

import (
	"os"
	"path/filepath"
	"strings"
	"testing"

	"mudscript/object"
)

func setupOverlayDirs(t *testing.T) (string, string) {
	t.Helper()
	root := t.TempDir()
	commonDir := filepath.Join(root, "common")
	worldDir := filepath.Join(root, "world")

	for _, dir := range []string{
		filepath.Join(commonDir, "include"),
		filepath.Join(commonDir, "std"),
		filepath.Join(commonDir, "cmds", "admin"),
		filepath.Join(worldDir, "include"),
		filepath.Join(worldDir, "cmds"),
		filepath.Join(worldDir, "rooms"),
	} {
		if err := os.MkdirAll(dir, 0755); err != nil {
			t.Fatalf("mkdir %s: %v", dir, err)
		}
	}
	return worldDir, commonDir
}

func writeTestFile(t *testing.T, path, content string) {
	t.Helper()
	if err := os.MkdirAll(filepath.Dir(path), 0755); err != nil {
		t.Fatalf("mkdir parent for %s: %v", path, err)
	}
	if err := os.WriteFile(path, []byte(content), 0644); err != nil {
		t.Fatalf("write %s: %v", path, err)
	}
}

func TestOverlayReadAndOverride(t *testing.T) {
	worldDir, commonDir := setupOverlayDirs(t)

	writeTestFile(t, filepath.Join(commonDir, "include", "config.h"), "#define MASTER_FILE \"/master.c\"\n#define LAYER \"common\"\n")
	writeTestFile(t, filepath.Join(commonDir, "std", "base.c"), "string query_layer() { return \"common\"; }\n")
	writeTestFile(t, filepath.Join(worldDir, "std", "override.c"), "string query_layer() { return \"world\"; }\n")
	writeTestFile(t, filepath.Join(commonDir, "std", "override.c"), "string query_layer() { return \"common_shadowed\"; }\n")

	d := New(DriverConfig{
		MudLibPath: worldDir,
		CommonPath: commonDir,
	})

	if master := d.DiscoverMasterFile(); master != "/master.c" {
		t.Fatalf("expected DiscoverMasterFile=/master.c, got %q", master)
	}

	content, err := d.ReadFile("/std/base")
	if err != nil || !strings.Contains(string(content), `"common"`) {
		t.Fatalf("expected fallback to common /std/base.c, got content=%q err=%v", string(content), err)
	}

	overrideContent, err := d.ReadFile("/std/override")
	if err != nil || !strings.Contains(string(overrideContent), `"world"`) {
		t.Fatalf("expected world override to shadow common, got content=%q err=%v", string(overrideContent), err)
	}
}

func TestOverlayChrootAndWritePinning(t *testing.T) {
	worldDir, commonDir := setupOverlayDirs(t)
	secretInCommon := filepath.Join(commonDir, "secret.txt")
	writeTestFile(t, secretInCommon, "untouched")

	writeTestFile(t, filepath.Join(commonDir, "master.c"), `
mixed valid_read(string path, object user, string func) { return 1; }
mixed valid_write(string path, object user, string func) { return 1; }
void create() {}
`)
	writeTestFile(t, filepath.Join(commonDir, "cmds", "tester.c"), `
int test_writes() {
    write_file("/data/out.txt", "world_only\n", 1);
    cp("/secret.txt", "/data/copied_secret.txt");
    rm("/secret.txt");
    return 1;
}
`)

	d := New(DriverConfig{
		MudLibPath: worldDir,
		CommonPath: commonDir,
		MasterFile: "/master.c",
	})
	if err := d.Start(); err != nil {
		t.Fatalf("driver start: %v", err)
	}
	defer d.Stop()

	// Chroot traversal without leading "/" must fail
	if _, err := d.ResolveWritePath("../common/secret.txt"); err == nil {
		t.Fatalf("expected chroot violation for ../common/secret.txt")
	}
	if _, err := d.ReadFile("../common/secret.txt"); err == nil {
		t.Fatalf("expected chroot violation on ReadFile traversal")
	}
	// Leading "/../" clamps at virtual root inside worldDir, never touching commonDir
	clampedPath, err := d.ResolveWritePath("/../common/secret.txt")
	if err != nil || !isWithinBase(worldDir, clampedPath) {
		t.Fatalf("expected /../common/secret.txt to clamp inside worldDir, got %q err=%v", clampedPath, err)
	}

	tester, err := d.LoadObject("/cmds/tester.c")
	if err != nil {
		t.Fatalf("load /cmds/tester.c: %v", err)
	}
	d.CallFunction(tester, "test_writes", nil)

	// Verify world data was written, while common remains completely untouched
	outData, err := os.ReadFile(filepath.Join(worldDir, "data", "out.txt"))
	if err != nil || string(outData) != "world_only\n" {
		t.Fatalf("expected worldDir/data/out.txt written, got %q err=%v", string(outData), err)
	}
	copied, err := os.ReadFile(filepath.Join(worldDir, "data", "copied_secret.txt"))
	if err != nil || string(copied) != "untouched" {
		t.Fatalf("expected cp from common to world data, got %q err=%v", string(copied), err)
	}
	commonData, err := os.ReadFile(secretInCommon)
	if err != nil || string(commonData) != "untouched" {
		t.Fatalf("common/secret.txt must remain untouched after rm(), got %q err=%v", string(commonData), err)
	}
}

func TestOverlayGetDirAndStat(t *testing.T) {
	worldDir, commonDir := setupOverlayDirs(t)

	writeTestFile(t, filepath.Join(commonDir, "cmds", "cmd_look.c"), "// common look\n")
	writeTestFile(t, filepath.Join(commonDir, "cmds", "cmd_say.c"), "// common say\n")
	writeTestFile(t, filepath.Join(commonDir, "cmds", "admin", "cmd_shutdown.c"), "// common admin\n")
	writeTestFile(t, filepath.Join(worldDir, "cmds", "cmd_look.c"), "// world custom look (longer)\n")
	writeTestFile(t, filepath.Join(worldDir, "cmds", "cmd_world.c"), "// world only\n")

	writeTestFile(t, filepath.Join(commonDir, "master.c"), `
mixed valid_read(string path, object user, string func) { return 1; }
void create() {}
`)
	writeTestFile(t, filepath.Join(commonDir, "cmds", "inspect.c"), `
mixed list_flat() { return get_dir("/cmds/"); }
mixed list_glob() { return get_dir("/cmds/cmd_*.c"); }
mixed list_rec()  { return get_dir("/cmds/", 1); }
int size_look()   { return file_size("/cmds/cmd_look.c"); }
int size_say()    { return file_size("/cmds/cmd_say.c"); }
mixed stat_say()  { return stat("/cmds/cmd_say.c"); }
`)

	d := New(DriverConfig{
		MudLibPath: worldDir,
		CommonPath: commonDir,
		MasterFile: "/master.c",
	})
	if err := d.Start(); err != nil {
		t.Fatalf("driver start: %v", err)
	}
	defer d.Stop()

	insp, err := d.LoadObject("/cmds/inspect.c")
	if err != nil {
		t.Fatalf("load inspect.c: %v", err)
	}

	flat := d.CallFunction(insp, "list_flat", nil).(*object.Array)
	var names []string
	for _, el := range flat.Elements {
		names = append(names, el.(*object.String).Value)
	}
	joined := strings.Join(names, ",")
	for _, want := range []string{"admin/", "cmd_look.c", "cmd_say.c", "cmd_world.c"} {
		if !strings.Contains(joined, want) {
			t.Fatalf("flat get_dir missing %q in %q", want, joined)
		}
	}
	if strings.Count(joined, "cmd_look.c") != 1 {
		t.Fatalf("expected deduplicated cmd_look.c in %q", joined)
	}

	glob := d.CallFunction(insp, "list_glob", nil).(*object.Array)
	if len(glob.Elements) != 3 {
		t.Fatalf("expected 3 glob matches (cmd_look, cmd_say, cmd_world), got %d", len(glob.Elements))
	}

	rec := d.CallFunction(insp, "list_rec", nil).(*object.Array)
	var recNames []string
	for _, el := range rec.Elements {
		recNames = append(recNames, el.(*object.String).Value)
	}
	if !strings.Contains(strings.Join(recNames, ","), "admin/cmd_shutdown.c") {
		t.Fatalf("expected recursive get_dir to include admin/cmd_shutdown.c, got %v", recNames)
	}

	szLook := d.CallFunction(insp, "size_look", nil).(*object.Integer).Value
	if szLook != int64(len("// world custom look (longer)\n")) {
		t.Fatalf("expected overridden world size, got %d", szLook)
	}
	szSay := d.CallFunction(insp, "size_say", nil).(*object.Integer).Value
	if szSay != int64(len("// common say\n")) {
		t.Fatalf("expected common fallback size, got %d", szSay)
	}
	stSay, ok := d.CallFunction(insp, "stat_say", nil).(*object.Array)
	if !ok || len(stSay.Elements) != 3 {
		t.Fatalf("expected stat() on common fallback to return 3-element array, got %#v", stSay)
	}
}

func TestCompileObjectVirtualFactory(t *testing.T) {
	worldDir, commonDir := setupOverlayDirs(t)

	writeTestFile(t, filepath.Join(commonDir, "std", "json_room.c"), `
string room_title;
void set_title(string t) { room_title = t; }
string query_title() { return room_title; }
string my_name() { return object_name(this_object()); }
string my_base() { return base_name(this_object()); }
`)
	writeTestFile(t, filepath.Join(worldDir, "rooms", "virtual_hall.json"), `{"title":"星門大廳"}`)
	writeTestFile(t, filepath.Join(commonDir, "master.c"), `
mixed valid_read(string path, object user, string func) { return 1; }
object compile_object(string path) {
    string json_path = path + ".json";
    if (file_size(json_path) > 0) {
        string raw = read_file(json_path);
        mapping data = json_decode(raw);
        object r = clone_object("/std/json_room.c");
        if (r && mapp(data)) {
            r->set_title(data["title"]);
            return r;
        }
    }
    return 0;
}
void create() {}
`)

	d := New(DriverConfig{
		MudLibPath: worldDir,
		CommonPath: commonDir,
		MasterFile: "/master.c",
	})
	if err := d.Start(); err != nil {
		t.Fatalf("driver start: %v", err)
	}
	defer d.Stop()

	room, err := d.LoadObject("/rooms/virtual_hall")
	if err != nil {
		t.Fatalf("LoadObject virtual room: %v", err)
	}

	title := d.CallFunction(room, "query_title", nil).(*object.String).Value
	if title != "星門大廳" {
		t.Fatalf("expected virtual room title '星門大廳', got %q", title)
	}
	objName := d.CallFunction(room, "my_name", nil).(*object.String).Value
	baseName := d.CallFunction(room, "my_base", nil).(*object.String).Value
	if objName != "/rooms/virtual_hall.c" || baseName != "/rooms/virtual_hall.c" {
		t.Fatalf("expected virtual object filename /rooms/virtual_hall.c, got objName=%q baseName=%q", objName, baseName)
	}
	if found := d.FindObject("/rooms/virtual_hall"); found != room {
		t.Fatalf("expected FindObject to locate virtual room")
	}

	d.DestructObject(room)
	if found := d.FindObject("/rooms/virtual_hall"); found != nil {
		t.Fatalf("expected DestructObject to clear virtual room from ObjectTable")
	}
}
