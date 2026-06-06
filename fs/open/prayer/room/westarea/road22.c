//open/prayer/room/westarea/road22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 西方可以到
	達"天璇門"與"玉衡門". 西邊較小的山脈人稱"曼麗山", 山
	林蒼翠, 綠意盎然, 一點也不像是西域的領土之一. 
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road21",		//街道
        "west":__DIR__"road23",		//街道
 
        ]) );
        set("objects",([ /* sizeof() ==  1*/
        "/open/prayer/npc/sister" : 1,		
        ]) );
        
        set("no_fight", 0);
    setup();
}
