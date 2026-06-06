//open/prayer/room/tanshun/17.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的西北方有兩個弟子正在蹲馬步. 原來是因為他
        們兩個睡過頭了, 所以被總教頭處罰! 看他們一臉懊悔的
        樣子, 好像也很自責! 往西是通往的總管書房的走廊.

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"16",             
        "south":__DIR__"21",            //練武場
        "west":__DIR__"18",     
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee1" : 1,              //弟子
  "/open/prayer/npc/trainee4" : 1,              //弟子
                
]));
     
  setup();
}
