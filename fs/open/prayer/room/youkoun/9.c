//open/prayer/room/youkoun/9.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的東北角, 有兩個女弟子提著茶水供大家飲用.
        看到那一大桶茶水, 你不禁感到有一點口渴了! 往東走是
        副門主的辦公房.

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"7",              //走廊
        "south":__DIR__"16",            //練武場
        "west":__DIR__"10",             //練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee3" : 1,                //弟子
        "/open/prayer/npc/trainee4" : 1,                //弟子
                
]));
     
  setup();
}
