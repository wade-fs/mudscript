//open/prayer/room/kiyan/21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	開陽門的練武場, 練武場上的弟子正在練功. 傳聞聖火教的武學
	共有三套, 其中之一的先天乾坤功, 威力無儔!!不過確是須要不 
	斷的練習!!南邊是開陽門與外界往來進出的大門, 你可以打開大
	門(open door).

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"14",		//練武場
	"south":__DIR__"2-door",	//練武場
	"west":__DIR__"22",		//練武場
	"east":__DIR__"20",		//練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee1" : 1,		//弟子
   		
]));

        set("light_up", 1);
        create_door("south","聖火刻紋精鋼大門", "north",DOOR_CLOSED);     
  setup();
}

