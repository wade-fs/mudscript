// /d/counties/qinghe/market.c
// 青河縣 (Qinghe County) 房間 3/14：百草糧油水集

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("青河縣・百草糧油水集");
    set_long("青河縣的中央市集沿著穿城而過的活水支渠鋪開，青石橋欄兩側擺滿了\n"
             "一簍簍帶著泥土芬芳的洗靈草、茯苓、苦參，以及大麻袋的新米與菜籽油。來自都城\n"
             "採百草分堂與糧市的坐莊牙人正在此驗看藥草成色。東面通往【東迎水陸關門】，西面是\n"
             "【青河縣衙】，北面為【青河洗藥總坊】，南面通往【百草坪梯田】，西南與東南分別是\n"
             "【通寶當鋪青河分號】與【青河縣驛】。\n");

    set_exits(([
        "east":      "/d/counties/qinghe/east_gate.c",
        "west":      "/d/counties/qinghe/yamen.c",
        "north":     "/d/counties/qinghe/herb_mill.c",
        "south":     "/d/counties/qinghe/baicaoping_fields.c",
        "southwest": "/d/counties/qinghe/pawnshop.c",
        "southeast": "/d/counties/qinghe/post_inn.c",
    ]));

    set_has_shop(1);
    set_coordinate(-8, 10, 0);
}
