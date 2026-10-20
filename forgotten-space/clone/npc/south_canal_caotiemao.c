// clone/npc/south_canal_caotiemao.c
// 曹鐵錨・碼頭水行把頭 (south_canal_caotiemao) - 西水門漕運碼頭

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("曹鐵錨");
    set_short(HIB "漕運水行把頭" NOR " 曹鐵錨");
    set_long("一位赤著古銅色上身、肩扛丈二鐵錨的魁梧漢子，嗓門洪亮如鐘。\n"
             "他統領西水門漕運碼頭的數百名翻砂苦力與船工，青河順流而下的平底糧船與藥船皆由他調度卸載。\n");
    set_id(({ "south_canal_caotiemao", "caotiemao", "cao tiemao", "dockmaster cao", "曹鐵錨", "水行把頭" }));

    setup_archetype("K", 25);
    set("class", "wu_initiate");
    set("faction", "folk");
    set("roles", ({ "service", "info", "quest_giver" }));
    set("rules", ([ "downstream_days": 3, "upstream_days": 5 ]));
    set("schedule", "day");

    add_response(({ "漕運", "青河", "駁船", "水路", "卸貨" }),
        "曹鐵錨吐了一口唾沫，洪聲道：「從青河縣裝船順流而下，兩天半到三天就能進咱西水門！要是逆流拉縴回去，少說也得五天！想在碼頭出力氣賺銅板儘管找老子！」");
}
