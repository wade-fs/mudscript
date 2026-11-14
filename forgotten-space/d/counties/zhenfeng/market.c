// /d/counties/zhenfeng/market.c
// 鎮風縣 (Zhenfeng County) 房間 2/14：皮甲硬弓邊集

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("鎮風縣・皮甲硬弓邊集");
    set_long("鎮風縣的中央集市建在高達兩丈的防風石牆背風處，地面鋪著防滑的粗紋\n"
             "青石板。集市攤位上沒有絲綢脂粉，全都是牛筋複合硬弓、三稜破甲獸骨箭鏃、雙層\n"
             "防寒狼皮甲，以及自天風谷絕壁採下的高純風蝕石英原石。往南回【南塞巨石甕城門】，\n"
             "向北登高通往【北塞防風石壩與烽燧】，西面是【鎮風縣衛所】，東面為【八方武館邊關分舵】，\n"
             "西南與東南分別坐落著【通寶當鋪鎮風分號】與【鎮風縣驛】。\n");

    set_exits(([
        "south":     "/d/counties/zhenfeng/south_gate.c",
        "north":     "/d/counties/zhenfeng/north_beacon.c",
        "west":      "/d/counties/zhenfeng/yamen.c",
        "east":      "/d/counties/zhenfeng/bafang_garrison.c",
        "southwest": "/d/counties/zhenfeng/pawnshop.c",
        "southeast": "/d/counties/zhenfeng/post_inn.c",
    ]));

    set_has_shop(1);
    set_coordinate(0, 17, 0);
}
