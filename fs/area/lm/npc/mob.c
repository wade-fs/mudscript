// /area/lm/npc/mob.c
// 輕量創界通用生物
#include <globals.h>
inherit NPC;

string icon = "👾";

void create() {
    
    set("name", select_lang(([ "en": "Mob", "zh-TW": "生物", "zh-CN": "生物" ])));
    set("short", select_lang(([ "en": "a mob", "zh-TW": "一隻生物", "zh-CN": "一只生物" ])));
    set("long", select_lang("這是一隻在創界中遊蕩的生物。\n"));
    set("id", ({"mob", "生物"}));

    set("level", 1);
    set("str", 5);
    set("dex", 5);
    set("con", 5);
    set("hp", query("max_hp"));
}

void set_icon(string i) {
    icon = i;
}

string query_icon() {
    return icon;
}
