// /d/wastes/north_road/cold_plain_entry.c
// 北境官道・黑風口雪坡 (Ch.83：八百里寒原初雪與雪豹蹤跡)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北境寒原・黑風口雪坡");
    set_long("踏過北境分水嶺，氣溫彷彿憑空往前推了整整一月。枯黃的狼尾草在北風裡\n"
             "伏成一片灰白，凍硬的車轍印積著剛落下的乾硬雪粒。路旁淺雪窪地印著一串\n"
             "寬約四寸的成年雪豹梅花足印，直斜切入西北亂石坡。\n"
             "往南退回【鎮風縣・望荒烽燧】，往北頂風前行可達【斷崖石棚驛站】。\n");

    set_exits(([
        "south": "/d/counties/zhenfeng/north_beacon.c",
        "north": "/d/wastes/north_road/post_station.c",
    ]));

    set("is_outdoor", 1);
}
