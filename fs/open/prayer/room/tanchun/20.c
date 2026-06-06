//open/prayer/room/tanchun/20.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	天權門的練武場, 練武場上的弟子正在訓練腿力. 傳聞聖火教的
	乾坤大挪移的步法, 能夠巧妙的避開敵人的攻擊!!並且可以出其
	不意地制敵於先機!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"16",		//練武場
	"south":__DIR__"26",		//練武場
	"west":__DIR__"21",		//練武場
	"east":__DIR__"19",		//練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee3" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
