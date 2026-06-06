//open/prayer/room/tanshun/26.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        一進入天璇門, 首先映入眼簾的是一大片的練武場!
        練武場上的弟子一個個都在磨練自己的體能, 一心希望
        能夠早一天具備修習先天乾坤功的資格!!

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"20",            //練武場
        "south":__DIR__"2-door",        //練武場
        "west":__DIR__"27",             //練武場
        "east":__DIR__"25",             //練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee2" : 1,                //弟子
        "/open/prayer/npc/trainee1" : 1,                //弟子
                
]));
        create_door("south","聖火刻紋精鋼大門", "north",DOOR_CLOSED);     
     
  setup();
}
