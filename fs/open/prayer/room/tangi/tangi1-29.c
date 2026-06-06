//open/prayer/room/tangi/tangi1-29.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",@LONG
此處是明教分部之一的天機門的走廊,走廊上可見到跑堂正在辛勞的四處奔波. 
南邊是廚房.
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/tangi/tangi1-36",		//廚房
	"north":"/open/prayer/room/tangi/tangi1-24",		//走廊
       
        ]) );
     
  setup();
}
