//open/prayer/room/tanshun/19.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的東方, 排著一整列的兵器, 有兩個弟子正在挑
        選合意的武器來練習. 不過挑了老半天, 好像都還沒有找
        到喜歡的, 真是傷腦筋..

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
