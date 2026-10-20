// /d/counties/zhongshi/market.c
// 重石縣 (Zhongshi County) 房間 2/14：石鐵大集

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("重石縣・石鐵大集");
    set_long("寬闊的條石廣場上整齊碼放著如小山般的重玄城防條石、粗生鐵錠與供武館\n"
             "淬骨所用的「黑鐵砂」。四周叮噹鑿石聲與鐵錘敲擊聲震耳欲聾，滿身石粉的石工與\n"
             "商會採買牙人正大聲議價。往西南通往【西南巨石甕城】，向北直達【北鎮條石關門】，\n"
             "西側為【重石縣衙】，東側是百工總會【重石石作總坊】，西北與東南分別為\n"
             "【通寶當鋪重石分號】與【磐石騾馬店】。\n");

    set_exits(([
        "southwest": "/d/counties/zhongshi/southwest_gate.c",
        "north":     "/d/counties/zhongshi/north_gate.c",
        "west":      "/d/counties/zhongshi/yamen.c",
        "east":      "/d/counties/zhongshi/stone_guild.c",
        "northwest": "/d/counties/zhongshi/pawnshop.c",
        "southeast": "/d/counties/zhongshi/post_inn.c",
    ]));

    set_has_shop(1);
    set_coordinate(-3, 6, 0);
}
