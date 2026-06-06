//open/prayer/room/westarea/road34.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華, 西邊是聖火教麾
	下的分部之一--"瑤光門". 瑤光門內全是女性, 不過聽說曾經有
	過一位男性進入, 之後便再也沒有人看見他了............  
LONG);

       	set("outdoors", "/u/r/rence");
       	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 2 */
       	"north":__DIR__"road31",		//街道
	"south":__DIR__"road39",		//街道
	"west":"/open/prayer/room/youkoun/2-door",		//大門
 
        ]) );
    setup();
}
