//open/prayer/room/westarea/road28.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 渾天水晶的存
	放地點只有教主本人才會知道, 至於聖火八天門的門主則均是
	由教主親自傳授的, 所以他們也不知道渾天水晶的下落. 東邊
	可以到達聖火教支門的"開陽門"與"陣勢門". 西邊是南北縱向
	的專用道路.
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road27",		//街道
        "west":__DIR__"road29",		//街道
 
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
