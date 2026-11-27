// /d/counties/qinghe/east_gate.c
// 青河縣 (Qinghe County) 房間 1/14：東迎水陸關門

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("青河縣・東迎水陸關門");
    set_long("這座臨水而築的青磚縣城東門，空氣中永遠飄散著一股清冽的洗靈草香與\n"
             "濕潤河風。城門外便是通往金石府城西關的沿河柳堤官道（280 里），門洞下絡繹\n"
             "不絕地通過推著獨輪藥車的藥農與糧商。向東出城即抵【青河半途水驛】，往西入城\n"
             "直達【百草糧油水集】，往南下坡通往【漕運平底駁船碼頭】，往北則是【青河水師營校場】。\n");

    set_exits(([
        "east":  "/d/routes/qinghe_post.c",
        "west":  "/d/counties/qinghe/market.c",
        "south": "/d/counties/qinghe/ferry_dock.c",
        "north": "/d/counties/qinghe/drill_ground.c",
    ]));

    set_coordinate(-7, 10, 0);
}
