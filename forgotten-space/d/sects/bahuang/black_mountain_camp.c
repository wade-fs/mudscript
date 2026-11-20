// /d/sects/bahuang/black_mountain_camp.c
// 八荒武山・黑山煞血營 (Ch.87：黑山前哨鐘台與雷烈駐營)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("八荒武山・黑山煞血營");
    set_long("黑石峽北側出口處的堅固石壘軍寨，迎面矗立著一座沉重的青銅報捷鐘台。\n"
             "校場上擺滿石鎖、鐵木椿與長槍架，兵甲碰撞聲與粗獷喝令此起彼落。獨臂老將\n"
             "雷烈手按寬鞘狂刀立於石階之上，檢閱著穿過試煉峽谷的新進武卒。\n"
             "向南返回【黑石峽試煉道】。\n");

    set_exits(([
        "south": "/d/sects/bahuang/black_stone_gorge.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/lei_lie.c");
}
