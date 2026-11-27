// /d/counties/liefan/tongtuo_ridge.c
// 烈礬縣 (Liefan County) 房間 13/14：孤狼嶺（銅駝嶺）・赤銅伴生礦區 (對應卷二 Ch.63)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("銅駝嶺・赤銅伴生礦區");
    set_long("孤狼嶺主峰下這片形如雙峰銅駝的赤色山嶺，是全府最大的赤銅與硝石伴生\n"
             "礦場。山坡上開鑿出數十個黑森森的斜井口，絞車木架旁堆滿了泛著孔雀綠與紫紅\n"
             "光澤的富銅礦石。向西下山回【烈礬百工冶煉分舵】，順著木梯向下 (down) 則可深入\n"
             "地火最盛的【銅駝嶺三號深井】。\n");

    set_exits(([
        "west": "/d/counties/liefan/smelting_branch.c",
        "down": "/d/counties/liefan/tongtuo_shaft3.c",
    ]));

    set_coordinate(9, 13, 0);
}
