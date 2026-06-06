//open/prayer/room/tanchun/13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	天權門副門主的書房. 副門主看來一副很忙碌的樣子, 應該是在
	幫門主處理門下的事務吧!!難怪門主有比較多的時間練武了....

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"12",		//副門主室
	"northeast":__DIR__"10",		
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/vice-chair" : 1,		
   "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
