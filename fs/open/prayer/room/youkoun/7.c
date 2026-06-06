//open/prayer/room/youkoun/7.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

        這裡是瑤光門副門主的辦公房. 有兩個女弟子正忙著遞送
        公文給副門主過目. 往東是副門主的書房, 往西則是通往
        練武場.

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"6",             //副門主室
        "south":__DIR__"8",             //副門主室
        "west":__DIR__"9",              //走廊
        "east":__DIR__"5",              //副門主室
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,                //弟子
        "/open/prayer/npc/trainee3" : 1,                //弟子
                
]));
     
  setup();
}

