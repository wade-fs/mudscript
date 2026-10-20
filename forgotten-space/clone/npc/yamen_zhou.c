// clone/npc/yamen_zhou.c
// 周捕頭・捕快總管 (yamen_zhou) - 金石府衙正堂

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("周捕頭");
    set_short(HIR "府衙捕快總管" NOR " 周捕頭");
    set_long("一位身穿皂隸公服、腰挎精鋼鎖鏈與判官鐵尺的精悍捕頭。\n"
             "他統領府城三班衙役與巡街遊徼，專司缉拿江洋大盜、彈壓城內凡胎私鬥與發布府衙懸賞。\n");
    set_id(({ "yamen_zhou", "zhou butou", "constable zhou", "周捕頭", "捕快總管", "捕頭" }));

    setup_archetype("C", 15);
    set("class", "wu_initiate");
    set("faction", "yamen");
    set("roles", ({ "guard", "quest_giver", "info" }));
    set("rules", ([ "brawl_fine": 500, "detention_days": 1 ]));
    set("schedule", "24h");

    add_response(({ "懸賞", "大案", "治安", "私鬥", "法網" }),
        "周捕頭拍了拍腰間鐵尺：「金石府城之內，修士受『絕靈法網』壓制，凡胎武夫私鬥則由本捕頭與巡街遊徼以鎖鏈鐵尺制伏！違律私鬥者，輕則罰銀五百文，重則下獄拘留一日！」");

    add_response(({ "黑石鋪", "趙德貴", "胡百戶" }),
        "周捕頭哼了一聲：「黑石關押解來的趙德貴與胡百戶，如今就關在後頭的府衙死牢裡，由鐵鐐張親自看管，等待府尹與兵備道會審！」");
}
