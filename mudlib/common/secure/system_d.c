// /secure/system_d.c
// 世界識別與核心設定守護進程

inherit "/std/object.c";

string mudlib_name;
string mudlib_id;

void create() {
    ::create();
    if (!restore_object("/data/system.o")) {
        mapping mf = query_world_manifest();
        mudlib_name = mf["name"] ? mf["name"] : "MudScript World";
        mudlib_id   = mf["mudlib_id"] ? mf["mudlib_id"] : (mf["world_id"] ? mf["world_id"] : "mudscript.world");
        save_object("/data/system.o");
    }
}

string query_mudlib_name() { return mudlib_name; }
string query_mudlib_id()   { return mudlib_id; }

void set_mudlib_name(string name, string id) {
    mudlib_name = name;
    mudlib_id   = id;
    save_object("/data/system.o");
}
