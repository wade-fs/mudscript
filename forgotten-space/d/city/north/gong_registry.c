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
}
