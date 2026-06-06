//open/prayer/room/tanchun/15.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	天權門的練武場, 練武場上的弟子正在接受總教頭的指導勤練外家
	功夫. 傳聞聖火教的武學三絕之一的先天乾坤功, 威力無儔!!不過
	需要不斷的練習自身的外家拳腳!!   

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"14",		//走廊
	"south":__DIR__"19",		//練武場
	"west":__DIR__"16",		//練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
