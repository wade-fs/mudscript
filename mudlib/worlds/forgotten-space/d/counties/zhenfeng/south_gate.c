// /d/counties/zhenfeng/south_gate.c
// 鎮風縣 (Zhenfeng County) 房間 1/14：南塞巨石甕城門 (對應卷二 Ch.61)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("鎮風縣・南塞巨石甕城門");
    set_long("這座扼守天風谷北口的邊塞縣城，城牆以重逾千斤的黑青條石混合鐵水澆築，\n"
             "厚達三丈，並設有雙層折角防風甕城以抵禦極北狂暴罡風。城門下駐守著披掛雙層\n"
             "狼皮重甲的邊防衛卒。向南出城即入【天風谷咽喉・飛沙隘口】（300 里通北關），\n"
             "往北穿過甕城直達【皮甲硬弓邊集】，往西通往【鷹嘴崖】，往東則是【碎冰堡】。\n");

    set_exits(([
        "south": "/d/routes/tianfeng_gorge_pass.c",
        "north": "/d/counties/zhenfeng/market.c",
        "west":  "/d/counties/zhenfeng/yingzui_cliff.c",
        "east":  "/d/counties/zhenfeng/suibing_fort.c",
    ]));

    set_coordinate(0, 16, 0);
}
