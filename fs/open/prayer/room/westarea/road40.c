//open/prayer/room/westarea/road40.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 東邊是通往飄渺四
	宮之一的"玄武宮". 北邊是聖火教的聖火八天門, 與聖火教比較起
	來, 飄渺城的勢力似乎明顯地小了很多!!
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 1 */
        "north":__DIR__"road35",		//街道

        ]) );
        set("no_fight", 0);
        
  setup();
}
