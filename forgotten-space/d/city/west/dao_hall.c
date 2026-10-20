// d/city/west/dao_hall.c
// 宣道司正堂 (法道受牒考核處、玄機真人)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("宣道司・三清正殿");
    set_long("整座大殿以青墨色玄石與古楠木構建，穹頂繪製著周天星斗與二十八宿逆行圖。\n"
             "殿內供奉著代表宇宙秩序的太虛天尊像，殿角四座銅爐升起嫋嫋龍涎檀香。\n"
             "宣道司道官玄機真人端坐於雲床法座之上，手持拂塵閉目養神。\n"
             "凡達到十級的修士，可向玄機真人請受法道一階度牒考核 (ask xuanji about 考核)。\n"
             "往東可步出正殿大門回到宣道司牌樓，向北通往靜心聽經閣，\n"
             "順生鐵旋梯向上 (up) 可登臨摘星觀象台。\n");

    set_exits(([
        "east":  "/d/city/west/dao_gate.c",
        "north": "/d/city/west/dao_quiet.c",
        "up":    "/d/city/west/dao_observatory.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/dao_xuanji.c");
}
