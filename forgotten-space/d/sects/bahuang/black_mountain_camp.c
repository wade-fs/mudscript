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
             "向南返回【黑石峽試煉道】，往西進入長城內側【傷兵養息院】，往東前往【北線軍寨炊事後勤區】，\n"
             "向北直登【北線長城巡防牆暨關口】。\n");

    set_exits(([
        "south": "/d/sects/bahuang/black_stone_gorge.c",
        "west":  "/d/sects/bahuang/restoration_hall.c",
        "east":  "/d/sects/bahuang/north_garrison_kitchen.c",
        "north": "/d/sects/bahuang/great_wall_gate.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/lei_lie.c");
}

void init() {
    ::init();
    add_action("do_compile", "compile");
}

int do_compile(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "manual" && arg != "roster" && arg != "操典" && arg != "安置名冊") {
        notify_fail("你想整編什麼軍務文書？試試：compile manual\n");
        return 0;
    }
    message_vision(HIR "$N與雷烈、岳停山、杜青禾、阿滿核實八十七人《北荒陣亡與重傷安置名冊》（含大伯燕山\n"
                       "黑冰斷谷失聯案備忘頁），並融合長呼吸氣血鎖儲、溫和降燥草藥與戰場輪替律，定稿\n"
                       "《黑山分段輪替操典》；旋於北端箭樓以普通鐵箭一舉無聲震碎三百步外青岩成粉！\n" NOR, me);
    if (!present("bahuang_rotation_manual", me)) {
        object ob = clone_object("/clone/item/bahuang_rotation_manual.c");
        if (ob) {
            ob->move(me);
            tell_object(me, HIY "你彙編領存《黑山分段輪替操典暨八十七人安置名冊》。\n" NOR);
        }
    }
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "compile", "target": "manual" ]));
    }
    return 1;
}
