// mudlib/area/lm/block_item.c
// Minecraft 方塊物品

#include <globals.h>

inherit OBJECT;

string block_type;

void create() {
    
    block_type = "stone";
}

void set_block_type(string t) {
    block_type = t;
    set("name", select_lang(t));
    set("short", select_lang(t + " 方塊"));
    set("long", select_lang("一塊 " + t + "，可以放置到世界中。\n"));
    set("id", ({ t, t + "_block", "block" }));
}

string query_block_type() { return block_type; }

string query_category() { return "Special"; }
