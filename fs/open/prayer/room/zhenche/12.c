//open/prayer/room/tanshun/12.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

        一進入辦公房, 可以很顯地感受到一股緊張忙碌的氣氛.
        有兩個弟子正在整理文件, 準備送給副門主過目. 從這兒
        往東直達副門主書房, 往西則是走廊的方向.

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"11",            //副門主室
        "south":__DIR__"13",            //副門主室
        "west":__DIR__"14",             //走廊
        "east":__DIR__"10",             //副門主室
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/trainee1" : 1,             //弟子
   "/open/prayer/npc/trainee3" : 1,             //弟子
                
]));
     
  setup();
}
