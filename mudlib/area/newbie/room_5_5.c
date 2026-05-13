#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(HIM("城鎮雜貨鋪"));
    set_long("這是一間琳瑯滿目的小店，貨架上堆滿了各式各樣的雜物：火把、繩索、乾糧、還有一些不知名的小零件。這裡販賣著各種旅行冒險必備的小東西。\n");
    set_no_combat(1);
    set_coordinate(5, 5, 0);
    add_exit("west", "/area/newbie/room_4_5.c");
    add_exit("south", "/area/newbie/room_5_4.c");
}
