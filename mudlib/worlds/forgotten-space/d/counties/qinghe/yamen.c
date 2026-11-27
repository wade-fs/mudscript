// /d/counties/qinghe/yamen.c
// 青河縣 (Qinghe County) 房間 4/14：青河縣衙・水政與藥稅堂

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("青河縣衙・水政藥稅堂");
    set_long("這座白牆黛瓦的江南式縣衙大堂內，懸掛著「活水濟民」四字匾額。大堂\n"
             "兩側除了常規的戶籍賦役冊外，最醒目的便是繪有全縣十二道支渠水閘與百草坪藥田\n"
             "分水比例的《青河水則圖》。近期上游定神道觀與下游糧農爭水不休，主簿案頭堆滿了\n"
             "雙方遞交的訴狀。向東回【百草糧油水集】，往西北沿河堤可直達【上游攔水濾沙石閘】。\n");

    set_exits(([
        "east":      "/d/counties/qinghe/market.c",
        "northwest": "/d/counties/qinghe/upper_dam.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(-9, 10, 0);
}
