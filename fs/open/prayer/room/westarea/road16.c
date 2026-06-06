//open/prayer/room/westarea/road16.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 東邊是進入聖
	火教分部之一的"天權門", 天權門的門主是位赤面書生, 使得
	一手好棍法, 可是真實的長相到底是如何就沒人得知了......
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road11",		//街道
	"south":__DIR__"road19",		//街道
	"east":"/open/prayer/room/tanchun/2-door",		//街道
	
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
