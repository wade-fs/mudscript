//open/prayer/room/tanchun/14.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",@LONG

	天權門的走廊，走廊的廊頂是使用上等的西域檜木建造的，隨時
	都會散發出特有的檜木香．西邊是練武場，順著走廊則可以到達
	副門主的辦公房．不過副門主不太喜歡女性進入他的辦公房....

LONG);

        set("outdoors", "/open/prayer");
        set("no_fight", 0);
	set("exits", ([ /* sizeof() == 2 */
	"east":__DIR__"12",		//走廊
        "west":__DIR__"15",		//走廊
 
        ]) );
        
  setup();
}
 int valid_leave(object me, string dir)
  {
    if(dir=="east"&&me->query("gender")=="女性")
        return notify_fail("女人是無法進入副門主的辦公房的 !\n");
        
   return 1;
}
