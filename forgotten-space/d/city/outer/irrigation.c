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

    set_touch("default", CYN "灌渠青石堤岸微濕長苔，水閘木輪摸上去沉實濕滑。" NOR);
    set_smell("default", HIG "清涼活水氣息混著岸邊青苔、泥鰍水腥與農田草香。" NOR);
    set_listen("default", CYN "活水湧出木製翻車與分水閘口的嘩啦流淌聲清脆悅耳。" NOR);

    spawn_npc("/clone/npc/outer_irrigation_engineer.c");
}
