// d/village/shed.c
// 黑石鋪・客棧背街・廢柴房 (流浪乞兒出生地)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("客棧背街・廢柴房");
    set_long("這是一間蜷縮在老客棧後巷陰暗處的破爛柴棚。屋頂泥草剝落，四周堆滿了\n"
             "發霉的潮濕朽木與碎瓦，唯有一角鋪著幾捆陳年稻草，算是唯一的棲身窩鋪。\n"
             "破爛木板的縫隙間，不時飄來前街客棧廚房的滾燙肉湯香氣與粗獷吆喝聲。\n"
             "角落裡放著一隻豁口的舊粗陶破碗，脖頸上那只縫滿補丁的粗布乾糧袋已磨得\n"
             "發黑。推開吱呀作響的柴門，鑽出泥濘後巷便是人聲鼎沸的青石街市。\n");

    set_exits(([
        "northeast": "/d/village/square.c",
    ]));

    set("is_outdoor", 0);

    spawn_npc("/clone/npc/mo_beggar.c");
}
