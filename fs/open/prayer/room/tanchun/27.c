//open/prayer/room/tanchun/27.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	練武場上的弟子正在練功. 傳聞聖火教的武學共有三套, 其
	中之一的渾天寶鑑心法, 是女媧娘娘所遺留下來的武學!!修
	習之後不但能增強本身的內力!!更能使得修習聖火教的武學
	有事半功倍的效果!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"21",		
        "east":__DIR__"26",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
  "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
