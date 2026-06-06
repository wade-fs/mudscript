// Room: /open/hall/jail/jail3.c

inherit ROOM;

#include <ansi.h>

void create()
{

        set("short", "死牢前走道");
        set("long", @LONG
此處沒有燈光，只能憑著從鐵窗外，照射下來的月光辨識東西!!站
在這裡可以很清楚的聽到，從死牢中傳來的咆哮聲～好像有許多猛獸被
關在裡面似的，嗯!?可這是關人的地方啊!?難道............
LONG);

        set("exits", ([ /* sizeof() == 1 */
  "south" :__DIR__"jail2",
  ]));

        setup();

}

