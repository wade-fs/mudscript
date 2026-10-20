// d/city/center/granary.c
// 府城常平倉 (官方糧儲與物價平抑核心)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・常平倉");
    set_long("這座以厚重條石與青磚深築的大糧倉佔地極廣，是全府戰略糧儲命脈。\n"
             "倉內堆疊著數以千計的沉重糧包，散發著稻麥與乾燥草料的純樸香氣。\n"
             "常平倉大使劉秉忠正手持斗秤與賬冊，核對來自青河縣水運駁船與近郊青禾田的入庫數目。\n"
             "一旦遇大旱秋澇，官府即於此處開倉平糶平抑物價。\n"
             "西南面邁出厚重大門可回到中央青石廣場。\n");

    set_exits(([
        "southwest": "/d/city/center/square.c",
        "east":      "/d/city/center/inn_main.c",
    ]));

    set("is_outdoor", 0);
}
