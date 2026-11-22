// /clone/npc/taixu_clerk_yanping.c
// 嚴平（太虛神宮・執律閣主簿，中階具名反派）(Ch.136, 148-149, 157-158)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("嚴平");
    set_short(HIB "執律閣主簿" NOR " 嚴平");
    set_long("一名面容清癯、總是捧著玉石核查簿的太虛神宮執律閣主簿，袖口偶爾透出一絲異域商棧硃砂氣。\n"
             "他嚴格盤查鹽晶折抵帳目，實則私挪餘屑暗售跨界掮客，最忌憚校星觀測院的實測誤差帳曝光。\n");
    set_id(({ "taixu_clerk_yanping", "clerk yanping", "yanping", "嚴平", "執律主簿" }));

    setup_archetype("G", 92);
    set("class", "dao");
    set("path", "fa");
    set("faction", "taixu_law");
    set("roles", ({ "antagonist", "quest" }));
    set("no_auto_attack", 1);
    set("home_room", "/d/realm/taixu/white_jade_steps.c");

    add_response(({ "鹽晶", "誤差", "校準", "檢索" }),
        "嚴平合上核查簿冷聲道：「天羅校準不容半分差池！下層鹽晶成色若再短缺，本主簿便只好依律\n"
        "請下星鎖檢索清查石堡藏匿的名冊了。」");
}
