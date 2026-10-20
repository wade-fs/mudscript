// clone/npc/wall_tower_w_navalofficer.c
// 水連環・水軍哨官 (wall_tower_w_navalofficer) - 西關譙樓

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("水連環");
    set_short(HIB "西關水軍哨官" NOR " 水連環");
    set_long("一位身穿防水油布软甲、手扶千斤鐵柵絞盤的水軍哨官，俯瞰著西水門水道與護城河。\n");
    set_id(({ "wall_tower_w_navalofficer", "shui lianhuan", "naval officer", "水連環", "水軍哨官", "哨官" }));

    setup_archetype("B", 20);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "guard", "info" }));
    set("schedule", "24h");

    add_response(({ "水門", "鐵柵", "絞盤", "護城河" }),
        "水連環按著鐵索絞盤道：「這道千斤重鐵柵由百工總會魯長生親手設計，一旦落下鎖死，莫說走私駁船，便是水鬼也休想從明渠游進城！」");
}
