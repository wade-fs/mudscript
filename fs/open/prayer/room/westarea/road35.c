//open/prayer/room/westarea/road35.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
	set( "build", 12 );
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 北邊是往陣勢
	門, 南邊是往玄武宮. 玄武宮是飄渺城四個分部之一. 有關聖
	火教的絕學渾天心法, 只能去找教主問個明白了!!
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road32",	//街道
	"south":__DIR__"road40",	//街道
	"west":__DIR__"road36",		//街道
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() ==  1*/
	"/open/prayer/npc/man2" : 1,		
        ]) );
  setup();
}
