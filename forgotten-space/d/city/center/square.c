// d/city/center/square.c
// 金石都城・青石中央廣場 (紅塵十字核心樞紐)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・中央青石廣場");
    set_long("此處是整座金石都城人口最密集、市井喧囂最盛的十字通衢大廣場。\n"
             "腳下鋪著自重石縣採掘打磨的厚重青石板，八方車馬人流在此匯聚穿梭。\n"
             "廣場中央立著高聳的官府告示木屏，說書盲叟在茶攤前手敲醒木講述大荒異聞，\n"
             "巡街遊徼身挎鐵尺按刀巡視。市井七情沉澱為淡淡的紅塵微濁。\n"
             "向北通往百工總會分業工坊街，向南直連金石商會六縣專材長街，\n"
             "往西走通向宣道司山門牌樓，往東行則是鎮武軍鎮外轅門，\n"
             "西北隅是威嚴的府衙正堂，東北角矗立著常平倉與金石大客棧 (enter/inn)，\n"
             "西南側坐落著金石學塾，東南側則是通寶錢莊與當鋪總號。\n");

    set_exits(([
        "north":     "/d/city/north/gong_gate.c",
        "south":     "/d/city/south/market_special.c",
        "west":      "/d/city/west/dao_gate.c",
        "east":      "/d/city/east/wu_gate.c",
        "northwest": "/d/city/center/yamen.c",
        "northeast": "/d/city/center/granary.c",
        "southwest": "/d/city/center/academy.c",
        "southeast": "/d/city/center/bank.c",
        "enter":     "/d/city/center/inn_main.c",
        "inn":       "/d/city/center/inn_main.c",
    ]));

    set("is_outdoor", 1);
    set("has_shop", 1);
    set("no_combat", 1);
}
