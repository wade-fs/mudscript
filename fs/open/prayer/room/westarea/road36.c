//open/prayer/room/westarea/road36.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 往東可以到達聖
	火教支門的"陣勢門". 陣勢門的規模雖然不會比天機門大, 可是
	勢力卻與天機門相去不遠, 原因是因為此門的門主是文星君的得
	意弟子!!北邊則是當鋪.
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"suhock",	//當鋪
        "east":__DIR__"road35",		//街道
        "west":__DIR__"road37",		//街道
 
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
