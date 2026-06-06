//open/prayer/room/tanshun/11.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

        天璇門內最近公務繁忙, 不得已只好多拉幾個弟子來幫忙
        . 不過看他們專心工作的情形, 好像一點抱怨也沒有, 對
        教內高層的命令完全地服從!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"12",            //副門主室
        "southeast":__DIR__"10",                
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/trainee2" : 1,             //弟子
   "/open/prayer/npc/trainee3" : 1,             //弟子
                
]));
     
  setup();
}
