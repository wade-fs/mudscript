// clone/npc/south_qianbaichuan.c
// 金石商會總堂副會長 錢百川 (shanghui_hq_qianbaichuan)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("錢百川");
    set_short(HIY "金石商會副會長" NOR " 錢百川");
    set_long("一位身著紫色暗雲紋綢緞長袍、腰懸雙魚玉佩的雍容巨賈。\n"
             "他端坐於金石商會總堂太師椅上，身後陳列著全府六大縣城的供銷明細大賬，\n"
             "掌管全城專材長街拍賣與跨縣大宗信用結算。前任大掌櫃蘇遠山驟逝後，\n"
             "他以副會長之尊暫代商會實權，城內金石大客棧掌櫃錢不換正是其同族堂弟。\n");
    set_id(({ "shanghui_hq_qianbaichuan", "qianbaichuan", "qian baichuan", "merchant chief", "錢百川", "副會長" }));

    setup_archetype("H", 45);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "info", "quest_target", "broker" }));
    set("schedule", "day");

    add_response(({ "商會", "信用", "交易", "六縣" }),
        "錢百川笑吟吟道：「青河之藥、烈礬之銅、盤木之材、鎮風之弓、重石之鐵，皆匯聚於金石總堂。唯有信用通暢，方能財源廣進。」");

    add_response(({ "天門引", "密室", "天字一號" }),
        "錢百川雙目神光一閃，斂去笑容：「天字一號密室乃前朝舊商盟地下重地，深埋太古玄鐵重門之下。無【天門引】與沈氏血親驗證，絕無可能開啟。」");

    add_response(({ "蘇遠山", "黑石鋪", "坩堝", "趙德貴" }),
        "錢百川面色不變，長嘆一聲：「蘇兄在黑石鋪遭逢不測，實乃我金石商會之痛。至於趙德貴私盜商隊器物，自有府衙鐵律嚴懲，與總堂何干？」");
}
