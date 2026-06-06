//open/prayer/room/westarea/road17.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華, 北邊可以通往
	聖火教的總壇. 聖火教的教主是謎一般的人物, 不過聽說他的
	悟性奇高, 並且文學深厚, 所以他自創了聖火教目前所擁有的
	三大絕學.........
LONG);

       	set("outdoors", "/open/prayer");
       	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 2 */
       	"north":__DIR__"road13",		//街道
	"south":__DIR__"road21",		//街道
	 
        ]) );
        setup();
}
