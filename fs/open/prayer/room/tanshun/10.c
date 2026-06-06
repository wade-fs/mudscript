//open/prayer/tanshun/10.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

        這裡是副門主的書房, 不過看樣子副門主並不在這裡,
        只有一位弟子正在整理副門主的書桌. 從這往西是通往
        走廊的方向.

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"11",                //副門主室
        "southwest":__DIR__"13",                //副門主室
        "west":__DIR__"12",             
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 1,              //弟子
                
]));
     
  setup();
}
