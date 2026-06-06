//open/prayer/room/uhen/4.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","玉衡門大廳");
        set("long",@LONG

	西武林中一個勢力龐大的組織, 人們統稱她為「聖火教」
	, 又稱為明教. 此處是明教分部之一的玉衡門, 門上所坐
	的是玉衡門的門主. 玉衡門是聖火教排行第五的支門．

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"1",	//門主房間
        "south":__DIR__"7",	//大廳
        "east":__DIR__"3",		//右護法
        "west":__DIR__"5",		//左護法
 
        ]) );
        set("light_up", 1);
        set("valid_startroom", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/uhen" : 1,		//門主
]));
  setup();
}
