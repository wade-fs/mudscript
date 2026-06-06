//open/prayer/room/youkoun/20.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        一進入瑤光門, 就可看到寬闊的練武場! 由於瑤光門只收
        女弟子, 因此廣場上練武的也都是女性! 微風吹來, 只聞
        到一股汗臭與體香混雜的奇妙味道..

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"17",            //練武場
        "south":__DIR__"2-door",        //練武場
        "west":__DIR__"21",             //練武場
        "east":__DIR__"19",             //練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee3" : 1,                //弟子
        "/open/prayer/npc/trainee1" : 1,                //弟子
                
]));

        create_door("south","聖火刻紋精鋼大門", "north",DOOR_CLOSED);     
  setup();
}
