// /d/counties/zhuoshui/post_inn.c
// 濁水縣 (Zhuoshui County) 房間 5/15：濁水縣驛・高腳吊腳樓

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("濁水縣驛・高腳吊腳樓");
    set_long("懸空架於濁水河面三丈之上的竹木吊腳客樓，四角點著驅蚊避瘴的雄黃艾草\n"
             "香盤。大堂內三教九流混雜，既有押送重晶石的行商，也有眼神陰鷙的黑市刀客。\n"
             "向西北走過木廊即回【浮橋金砂水集】。\n");

    set_exits(([
        "northwest": "/d/counties/zhuoshui/market.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(7, 5, 0);
}
