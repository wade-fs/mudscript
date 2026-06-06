//open/prayer/room/westarea/road39.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 北邊是往瑤光門,
	南邊是往朱雀宮. 飄渺城是西域的一另一個教派, 雖然說分佈的範
	圍較分散, 可是其隱藏的實力到現在仍是一個未知的變數.
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road34",	//街道
	"south":__DIR__"road41",	//街道
	"east":__DIR__"road38",		//街道
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() ==  1*/
	"/open/prayer/npc/woman3" : 1,		
        ]) );

  setup();
}
