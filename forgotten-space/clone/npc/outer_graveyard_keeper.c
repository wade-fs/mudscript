// clone/npc/outer_graveyard_keeper.c
// 守塚老瞎子・守塚人 (outer_graveyard_keeper) - 城外亂葬義塚

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("守塚老瞎子");
    set_short(WHT "義塚守墓人" NOR " 守塚老瞎子");
    set_long("一位右腿微瘸、左眼蒙著灰布的孤苦老漢，手拄一把磨得發亮的掘土鐵鍬。\n"
             "他常年守在北門外的亂葬義塚，為無名客死之流民掩埋屍骨，對夜間墳地滋生的陰煞藥材與棄屍暗殺知之甚詳。\n");
    set_id(({ "outer_graveyard_keeper", "graveyard keeper", "old blind keeper", "守塚老瞎子", "守塚瘸瞎老漢", "守墓人" }));

    setup_archetype("J", 12);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "service", "info", "quest_giver" }));
    set("schedule", "24h");

    add_response(({ "亂葬崗", "義塚", "夜煞", "暗殺", "甦醒" }),
        "守塚老瞎子拄著鐵鍬沙啞道：「在城裡丟了性命或是熬不過三日通牒的可憐人，最後都歸老漢這片黃土坡……不過逢著陰煞之夜，新墳頭上倒常長出能入偏方的夜煞陰草。」");
}
