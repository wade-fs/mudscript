// by roger
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","芙蓉湖旁");
set ("long", @LONG
    這裡是芙蓉湖畔，道路一邊臨湖，一邊是整排的雕樓畫棟。江水滔滔，
風煙平闊，樓上樓下，仍有不少風流名士的墨跡詞章。連同煙花女子，也停
舟湖上，蕭招琴撫，陪客侑酒。陽光依依，秋風迎面，帶來幾片殘葉，遠處
玉笛，不知何人斷了又續，續了又斷。 
LONG);


  set("exits", ([
            "east"  : __DIR__"room2",
            "west"  : __DIR__"room3",
                ]));

       

        setup();
}
