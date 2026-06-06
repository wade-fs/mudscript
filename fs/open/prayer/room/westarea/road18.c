//open/prayer/room/westarea/road18.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華, 西邊是聖火八
	天門之一--"天璇門". 門主是一位美麗的女性, 是一位中原人
	士, 不過聽說已經結婚了!!她的夫婿好像也是聖火教的一位門
	主......
LONG);

        set("outdoors", "/open/prayer");
        set("no_fight", 0);
	set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road15",		//街道
	"south":__DIR__"road23",		//街道
	"west":"/open/prayer/room/tanshun/2-door",		//大門
 
        ]) );
        
        setup();
}
