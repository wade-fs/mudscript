// clone/npc/wall_tower_e_beaconchief.c
// 耿烽・烽火長 (wall_tower_e_beaconchief) - 東關箭樓

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("耿烽");
    set_short(HIR "東城烽火長" NOR " 耿烽");
    set_long("一位臉龐被狼煙熏得微黑的老成軍官，守在東關箭樓的三座常備狼煙烽燧旁。\n");
    set_id(({ "wall_tower_e_beaconchief", "geng feng", "gengfeng", "beacon chief", "耿烽", "烽火長" }));

    setup_archetype("B", 20);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "guard", "info" }));
    set("schedule", "24h");

    add_response(({ "烽火", "狼煙", "東關", "烈礬" }),
        "耿烽指著三座大石烽燧道：「這烽燧裡填的是烈礬縣上好的硫磺與乾狼糞，一旦點起三道赤煙，五十里外的駐軍都能看見！」");
}
