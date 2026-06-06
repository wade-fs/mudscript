//open/prayer/room/kiyan/15.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	開陽門的練武場, 練武場上的弟子正在練功. 傳聞聖火教的武學
	共有三套, 其中之一的先天乾坤功, 威力無儔!!可是正是因為如 
	此, 所以根基絕對不能夠太差, 以免因此而造成自身的危害!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
 	"east":__DIR__"14",		
	"south":__DIR__"22",		//練武場
	"west":__DIR__"17",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
 int valid_leave(object me, string dir)
  {
    if(dir=="west"&&me->query("gender")=="男性")
        return notify_fail("男人是無法進入總管的辦公房的 ?\n");
        
   return 1;
}
