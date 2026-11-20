// /d/sects/taiqing/outer_court.c
// 太清玄天宮・外門雲舍 (Ch.86)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清玄天宮・外門雲舍");
    set_long("雲頂絕峰背風處一排整齊清冷的青瓦石舍，為外門經生抄校星圖、謄寫氣朔錄及\n"
             "日常吐納調息之所。院中冷松積雪未融，空氣稀薄卻不含半分紅塵濁氣。\n"
             "向南退至【登天雲梯山門】，往北步入【周天星律院】。\n");

    set_exits(([
        "south": "/d/sects/taiqing/gate.c",
        "north": "/d/sects/taiqing/star_law_hall.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/shen_zhaochen.c");
}
