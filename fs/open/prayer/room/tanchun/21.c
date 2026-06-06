//open/prayer/room/tanchun/21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	練武場上的弟子一個個都在磨練自己的體能，只希望能夠早一天
	具備修習先天乾坤功的資格!!而先天乾坤功一共有一十二式, 每 
	一式都有著意想不到的變招, 可是要學得十成的火侯, 就得要先
	天的悟性加上後天的努力了!! 

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"17",		//練武場
	"south":__DIR__"27",		//練武場
	"east":__DIR__"20",		//練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
