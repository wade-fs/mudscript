//open/prayer/room/zhenche/19.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的東方, 排著一整列的磚塊, 有兩個弟子正在練
        習劈磚! 不過劈了老半天, 好像都還沒有找到竅門的樣子
        , 看他們的手都已經腫起來了, 真是傷腦筋..

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"15",            //練武場
        "south":__DIR__"25",            //練武場
        "west":__DIR__"20",             //練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,              //弟子
  "/open/prayer/npc/trainee3" : 1,              //弟子
                
]));
     
  setup();
}
