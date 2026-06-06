//open/prayer/room/westarea/road24.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 東邊是進入聖
	火教分部之一的"開陽門", 門主是中原隱歸的一位師太, 身懷
	其本家絕學, 貴為掌門人, 可是卻跑到西域來當一個門的門主
	, 難道這其中......
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road19",		//街道
	"south":__DIR__"road27",		//街道
	"east":"/open/prayer/room/kiyan/2-door", //街道
	
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
