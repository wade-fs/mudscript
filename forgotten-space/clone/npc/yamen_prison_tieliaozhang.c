// clone/npc/yamen_prison_tieliaozhang.c
// 鐵鐐張・獄頭 (yamen_prison_tieliaozhang) - 府衙死牢

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("鐵鐐張");
    set_short(WHT "府衙死牢獄頭" NOR " 鐵鐐張");
    set_long("一位滿臉橫肉、手提一大串沉重玄鐵牢門鑰匙的老獄頭。\n"
             "他在陰暗潮濕的府衙死牢當差二十餘載，看押過無數江洋巨寇與失勢官吏，深諳牢獄規矩。\n");
    set_id(({ "yamen_prison_tieliaozhang", "tieliaozhang", "tie liao zhang", "warden zhang", "鐵鐐張", "獄頭" }));

    setup_archetype("B", 25);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "guard", "info" }));
    set("schedule", "24h");

    add_response(({ "探監", "重犯", "趙德貴", "胡百戶", "審訊" }),
        "鐵鐐張晃了晃手裡的玄鐵鑰匙，陰惻惻道：「裡頭關著的可是黑石鋪礦案的要犯趙德貴和胡百戶！兵備道與府尹下了嚴令，沒帶手諭誰也別想劫獄，不過隔著鐵柵問兩句話，老子倒可以睜隻眼閉隻眼。」");
}
