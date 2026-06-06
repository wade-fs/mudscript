//open/prayer/room/westarea/road29.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
	set( "build", 12 );
        set("long",@LONG
	十字路口. 同時也是聖火教的南北快速道路. 往北邊走可以
	到達聖火教的總壇. 往南則是通往中原武林的要道. 四方到
	處可見聖火教的各個支門..西邊有一家錢莊, 你可以在那裡
	存放銀兩!!
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
       	"north":__DIR__"road25",	//街道
	"south":__DIR__"road33",	//街道
	"east":__DIR__"road28",		//街道
	"west":__DIR__"road30",		//街道

        ]) );
        set("no_fight", 0);
        
  setup();
}
