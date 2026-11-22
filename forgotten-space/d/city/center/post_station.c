// d/city/center/post_station.c
// 官辦遞鋪驛館 (官方公文快郵、加急送信)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・官辦遞鋪驛館");
    set_long("此處是金石都城承轉朝廷律令、公文快郵與商盟急信之官辦驛館。\n"
             "馬棚內拴著數匹神駿的神行黃驃馬，牆上插滿了六大縣城路線圖與公文簽牌。\n"
             "府城驛丞馬千里正手按加急火漆信匣，審核快馬換乘公驗。\n"
             "向西走出驛館大門可回到金石大客棧。\n");

    set_exits(([
        "west": "/d/city/center/inn_main.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", YEL "驛館公文木架邊沿被急遞信差擦得油滑，桌上火漆印章尚帶餘溫。" NOR);
    set_smell("default", YEL "馬棚乾草、快馬汗味、熱蠟封口與官道郵袋上的乾燥塵土氣。" NOR);
    set_listen("default", HIY "庭院急遞駿馬嘶鳴與信差腰間銅鈴由遠而近的急促「叮鈴」響動。" NOR);

    spawn_npc("/clone/npc/post_station_maqianli.c");
}
