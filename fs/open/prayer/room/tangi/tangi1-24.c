//open/prayer/room/tangi/tangi1-24.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",
"走廊的盡頭是天機門的廚房，往北則可以到達大廳，西邊是總管的處理門務的
地方.\n");

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/tangi/tangi1-19",		//走廊
	"south":"/open/prayer/room/tangi/tangi1-29",		//走廊
	"west":"/open/prayer/room/tangi/tangi1-44",		//總管辦公室
       
        ]) );

  setup();
}
 int valid_leave(object me, string dir)
  {
    if(dir=="west"&&me->query("gender")=="男性")
        return notify_fail("男人是無法進入總管的辦公房的 ?\n");
        
   return 1;
}
