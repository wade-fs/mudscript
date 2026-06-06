//open/prayer/room/kiyan/20.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	開陽門的練武場, 練武場上的弟子們正在練功,傳聞聖火教的武學共
	有三套,其中之二的渾天寶鑑心法, 是女媧娘娘所遺留下來的武學!!
	修習之後不但能增強本身的內力!!更能發揮許多另人嘆為觀止的驚人
	美技!!

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"13",		
        "west":__DIR__"21",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
