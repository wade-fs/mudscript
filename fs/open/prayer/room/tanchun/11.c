//open/prayer/room/tanchun/11.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	天權門副門主的辦公房. 負責護衛工作的弟子眾多, 守備森嚴, 
	他們除了保護副門主的安全之外, 也代表了聖火教對高級幹部的
	一種尊重.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"12",		//副門主室
	"southeast":__DIR__"10",		
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/trainee2" : 1,		//弟子
   "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
