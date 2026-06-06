//open/prayer/zhenche/15.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的東北角, 有兩個弟子正在沙盤推演, 似乎對
        才所學的陣法有所領悟的樣子. 從這往東則是通往副門
        主辦公房的走廊.

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"14",             //走廊
        "south":__DIR__"19",            //練武場
        "west":__DIR__"16",             //練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,              //弟子
  "/open/prayer/npc/trainee4" : 1,              //弟子
                
]));
     
  setup();
}
