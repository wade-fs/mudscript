// /d/counties/zhuoshui/market.c
// 濁水縣 (Zhuoshui County) 房間 2/15：浮橋金砂水集

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("濁水縣・浮橋金砂水集");
    set_long("由縱橫交錯的寬闊木棧道與連環浮橋組成的中央水集，空氣中混雜著潮濕\n"
             "水腥、艾草煙與江湖草莽的悍氣。攤位上公開或半公開地交易著自上游沖刷而下的\n"
             "粗金砂、重晶石、水磨碎礦與封在蠟丸裡的劇毒獸囊。北面回【北鎮高腳木樁門】，\n"
             "南面通往暗流洶湧的【黑水埗・三號木樁浮橋】，西面是【濁水縣署】，東面為【濁水百草毒理棚】，\n"
             "西南與東南分別坐落著【通寶當鋪濁水分號】與【濁水縣驛】。\n");

    set_exits(([
        "north":     "/d/counties/zhuoshui/north_gate.c",
        "south":     "/d/counties/zhuoshui/heishui_pontoon.c",
        "west":      "/d/counties/zhuoshui/yamen.c",
        "east":      "/d/counties/zhuoshui/venom_shed.c",
        "southwest": "/d/counties/zhuoshui/pawnshop.c",
        "southeast": "/d/counties/zhuoshui/post_inn.c",
    ]));

    set_has_shop(1);
    set_coordinate(6, 6, 0);
}
