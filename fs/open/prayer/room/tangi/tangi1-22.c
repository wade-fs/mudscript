//open/prayer/room/tangi/tangi1-22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",
"天機門的走廊，走廊上可見到跑門正在辛勞的四處奔波，走廊的廊頂是使用上等的
西域檜木建造的，隨時都會散發出特有的檜木香．西邊與南邊是練武場，順著走廊
則可以到達副門主的辦公房．\n");

        set("outdoors", "/u/r/rence");
        set("no_fight", 0);
	set("exits", ([ /* sizeof() == 3 */
        "south":"/open/prayer/room/tangi/tangi1-27",		//練武場
	"east":"/open/prayer/room/tangi/tangi1-23",		//走廊
        "west":"/open/prayer/room/tangi/tangi1-21",		//走廊
 
        ]) );
        
  setup();
}
