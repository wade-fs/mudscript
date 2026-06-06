//open/prayer/room/tanchun/18.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",@LONG

	天權門的走廊，走廊的廊頂是使用上等的西域檜木建造的，隨時
	都會散發出特有的檜木香．東邊是練武場，順著走廊則可以到達
	總管的辦公房．總管的辦公房可是不准男性進入的呢!!

LONG);

        set("outdoors", "/open/prayer");
        set("no_fight", 0);
	set("exits", ([ /* sizeof() == 2 */
	"east":__DIR__"17",		//走廊
        "south":__DIR__"23",		//走廊
 
        ]) );
        set("objects",([ /* sizeof() ==  1*/
        "/open/prayer/npc/lu" : 1,		
        ]) );        

        
  setup();
}

int valid_leave(object me, string dir)
  {
    if(dir=="south"&&me->query("gender")=="男性")
        return notify_fail("男人是無法進入總管的辦公房的 ?\n");
        
   return 1;
}
