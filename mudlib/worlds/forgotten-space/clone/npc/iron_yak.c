// /clone/npc/iron_yak.c
// 鐵甲寒犛・北線長城二階荒獸 (iron_yak) - 北線長城巡防牆暨關口 (Ch.93)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("鐵甲寒犛");
    set_short(HIB "二階成年・鐵甲寒犛" NOR);
    set_long("一頭體長近兩丈的二階北荒荒獸，通體覆著層層交疊的灰黑色鱗甲與厚重凍泥，\n"
             "頭頂一對彎曲如黑鐵鉤的玄鐵牛角閃著寒光，正朝著三號豁口的補給馬隊狂衝而來！\n");
    set_id(({ "iron_yak", "iron yak", "yak", "鐵甲寒犛", "寒犛" }));

    setup_archetype("D", 70);
    set("class", "beast");
    set("faction", "wastes_beast");
    set("home_room", "/d/sects/bahuang/great_wall_gate.c");

    set_exp_reward(950);
    set_gold_reward(200);
    set_drop_list(({ "/item/material/wolf_fur.c" }));
    set_respawn(60);
    set_aggro_msg("鐵甲寒犛鼻孔噴出兩道丈許長白霧，低頭壓角踏碎積雪，朝著前陣狠撞過來！\n");
    set_special_atk("玄角衝撞", 42);
}
