//open/prayer/room/rwestarea/road26.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華, 西邊是聖火
	教麾下的分部之一--"玉衡門". 玉衡門主是位西域土生土長
	的美人, 身材標致, 對於乾坤大挪移的造詣已經達到頂峰, 
	所以輕功更是一絕......
LONG);

       	set("outdoors", "/u/r/rence");
       	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road23",		//街道
	"south":__DIR__"road31",		//街道
      "west":"/open/prayer/room/uhen/2-door",         //大門
 
        ]) );
        setup();
}
