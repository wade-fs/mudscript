// /d/counties/qinghe/baicaoping_fields.c
// 青河縣 (Qinghe County) 房間 13/14：百草坪・桑竹靈草梯田 (轄下新手村 2，對應卷二 Ch.58)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("百草坪・桑竹靈草梯田");
    set_long("順著青河南岸的向陽緩坡層層疊疊開墾出的百畝藥圃梯田，田埂間栽種著\n"
             "防風固土的翠竹與矮桑。梯田裡隨處可見戴著斗笠的藥農正在疏通毛渠、採摘成熟\n"
             "的洗靈草與白朮。向北進城即抵【百草糧油水集】，往西走入竹林是【曬藥竹棚與烘房】，\n"
             "往南攀上山脊則踏入通往重石縣的【西嶺支脈山道】（160 里）。\n");

    set_exits(([
        "north": "/d/counties/qinghe/market.c",
        "west":  "/d/counties/qinghe/baicaoping_drying.c",
        "south": "/d/routes/west_ridge_trail.c",
    ]));

    set_coordinate(-8, 9, 0);
}
