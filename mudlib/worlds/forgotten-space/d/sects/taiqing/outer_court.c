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
        "east":  "/d/sects/taiqing/scripture_copy_hall.c",
        "west":  "/d/sects/taiqing/outer_dormitory.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "外門雲舍青石院坪掃得乾淨微涼，廊柱紅漆在山風裡略顯斑駁。" NOR);
    set_smell("default", CYN "清淡鬆香、早課焚餘的白檀香灰與山嵐水汽令人神清氣爽。" NOR);
    set_listen("default", HIC "外門弟子整齊的誦經早課聲自東側抄經堂飄來，間雜幾聲清越山鳥啼鳴。" NOR);

    spawn_npc("/clone/npc/shen_zhaochen.c");
}
