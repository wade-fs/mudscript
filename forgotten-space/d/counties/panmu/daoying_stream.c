// /d/counties/panmu/daoying_stream.c
// 盤木縣 (Panmu County) 房間 13/14：倒影澗・古林界碑

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("倒影澗・古林界碑");
    set_long("清澈冰涼的山澗水倒映著兩岸參天古木，溪畔立著一塊長滿青苔的青石界碑，\n"
             "上刻「倒影澗以北禁伐古林，留護水土與獸道」。界碑旁的淺灘上卻散落著新近鋸斷\n"
             "的冷杉木屑與斷裂的麻繩。往西返回【巡山獵武堂】，向北涉溪而上便是商會林班\n"
             "正在作業的【古冷杉伐木線】。\n");

    set_exits(([
        "west":  "/d/counties/panmu/hunter_lodge.c",
        "north": "/d/counties/panmu/fir_logging_line.c",
    ]));

    set_coordinate(5, 7, 0);
}
