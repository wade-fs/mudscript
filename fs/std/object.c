// /std/object.c - 移植與相容性基底類別 (Legacy fs 版)

#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

void create() {
    seteuid(getuid());
}

// ── 相容性 Wrapper ──────────────────────────────────────
void set_name(mixed n) { set("name", n); }
void set_short(mixed s) { set("short", s); }
void set_long(mixed s)  { set("long", s); }
void set_id(mixed id)   { set("id", id); }

string query_name() { return query("name"); }
string query_short() { return query("short"); }
string query_long() { return query("long"); }
mixed query_id() { return query("id"); }

int move(mixed dest) {
    return move_object(this_object(), dest);
}

void setup() {
    seteuid(getuid());
}
