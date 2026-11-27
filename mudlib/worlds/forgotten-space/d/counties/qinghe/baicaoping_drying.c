// /d/counties/qinghe/baicaoping_drying.c
// 青河縣 (Qinghe County) 房間 14/14：百草坪・曬藥竹棚與烘房 (對應卷二 Ch.58-60)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("百草坪・曬藥竹棚與烘房");
    set_long("數十座通風竹棚與地火微溫烘房連成一片，竹匾上鋪滿了剛洗淨切片的\n"
             "洗靈草、苦參、車前子與地膚草。金石秋歲連陰雨時節，全靠這幾座烘房以桑柴微火\n"
             "日夜焙乾，方能保住銷往都城醫館的藥材不致受潮霉變。往東走出竹棚即回【百草坪・桑竹靈草梯田】。\n");

    set_exits(([
        "east": "/d/counties/qinghe/baicaoping_fields.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(-9, 9, 0);
}
