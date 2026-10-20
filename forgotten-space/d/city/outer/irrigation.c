// d/city/outer/irrigation.c
// 金石府外・青河水閘與渠首

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("青河水閘・渠首樞紐");
    set_long("此處是引青河活水注入金石護城河與城西渠網的重型水利樞紐。\n"
             "青黑色的巨型青石水壩橫截水面，沉重的水閘絞盤以青銅索具懸吊。\n"
             "幾名治水工丞正俯身觀測水尺刻度，隨時調整進水量以防內河澇旱。\n"
             "南面沿渠埂可通往城西青禾田，向東沿江岸可望見巍峨的西水門重鐵閘。\n");

    set_exits(([
        "south": "/d/city/outer/farmland_w.c",
        "east":  "/d/city/gate/gate_west.c",
    ]));

    set("is_outdoor", 1);

    spawn_npc("/clone/npc/outer_irrigation_engineer.c");
}
