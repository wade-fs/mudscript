//open/prayer/room/zhenche/21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的西方, 有兩個弟子正互相眉來眼去! 原來他們
        原本是一對夫妻, 又因為愛慕聖火的武功威名, 因此相協
        進入陣勢門中習武.

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"17",            //練武場
        "south":__DIR__"27",            //練武場
        "east":__DIR__"20",             //練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,              //弟子
  "/open/prayer/npc/trainee3" : 1,              //弟子
                
]));
     
  setup();
}
