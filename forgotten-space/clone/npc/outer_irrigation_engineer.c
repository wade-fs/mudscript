// clone/npc/outer_irrigation_engineer.c
// 河伯孫・治水工丞 (outer_irrigation_engineer) - 青河水閘與渠首

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("河伯孫");
    set_short(HIB "青河治水工丞" NOR " 河伯孫");
    set_long("一位手持水準木尺與水文圖譜的百工水利匠官，站在青河分水大閘上觀測水尺刻度。\n"
             "他調節的水閘開合直接決定城西青禾田的灌溉、西水門漕船吃水深度以及城內地下暗渠的排濁水位。\n");
    set_id(({ "outer_irrigation_engineer", "hebo sun", "irrigation engineer", "河伯孫", "治水工丞", "工丞" }));

    setup_archetype("E", 22);
    set("class", "gong_initiate");
    set("faction", "gong");
    set("roles", ({ "service", "quest_giver", "info" }));
    set("schedule", "day");

    add_response(({ "水閘", "治水", "水位", "濁氣", "暗渠" }),
        "河伯孫指著滾滾水流道：「這座青河渠首大閘乃是全城水脈總樞！開大三分則沖刷城下太古暗渠、洗淨城內沉積濁氣；關小三分則蓄水保西水門重載漕船通行，分毫皆是學問！」");
}
