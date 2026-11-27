// d/city/north/gong_registry.c
// 百工總會・匠籍登記處

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工總會・匠籍登記處");
    set_long("此處是百工總會核銷各縣原料調撥批件與頒發學徒考牌之官辦署所。\n"
             "司匠簿吏伏案批註，牆上插滿了六大縣城的調材令牌。\n"
             "凡欲調用烈礬赤銅或盤木鐵力木之工坊匠人，皆需在此核驗匠籍。\n"
             "西面推門走出即為百工總會外門坊口。\n");

    set_exits(([
        "west": "/d/city/north/gong_gate.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "牆上插滿六大縣城的調材令牌硬木微涼，登記簿紙頁翻得邊角起毛。" NOR);
    set_smell("default", CYN "新刷公文墨汁味、印泥與密閉檔案櫃裡的乾燥樟木氣息。" NOR);
    set_listen("default", WHT "算盤珠偶爾一撥、毛筆尖在竹紙上沙沙批註與匠人等候驗牌的輕咳聲。" NOR);

    spawn_npc("/clone/npc/gong_registry_clerk.c");
}
