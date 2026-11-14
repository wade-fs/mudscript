// /d/counties/zhenfeng/yingzui_cliff.c
// 鎮風縣 (Zhenfeng County) 房間 11/14：鷹嘴崖・散人避風石窟 (轄下新手村 1，對應卷二 Ch.61)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("鷹嘴崖・散人避風石窟");
    set_long("天風谷西側一處形如巨鷹勾喙的突出危崖下，依著天然岩洞開鑿出數十間\n"
             "避風石窟，聚居著不願入衛所軍籍的採石散人與老獵手。石窟外掛著攀崖用的飛爪\n"
             "百丈索與鐵鎬。向東順山徑可返【鎮風縣・南塞巨石甕城門】，順著絕壁鐵索向上攀爬 (up)\n"
             "則可直達罡風最烈的【鷹嘴崖・風蝕石英礦脈】。\n");

    set_exits(([
        "east": "/d/counties/zhenfeng/south_gate.c",
        "up":   "/d/counties/zhenfeng/yingzui_quartz.c",
    ]));

    set_coordinate(-1, 16, 0);
}
