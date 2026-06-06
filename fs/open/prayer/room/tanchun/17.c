//open/prayer/room/tanchun/17.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	練武場上的弟子一個個都在磨練自己的體能，只希望能夠早一天
	具備修習聖火教絕學的資格!!瞧他們努力的樣子, 自己都開始有
	點想要加入聖火教了.

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"16",		
	"south":__DIR__"21",		//練武場
	"west":__DIR__"18",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
