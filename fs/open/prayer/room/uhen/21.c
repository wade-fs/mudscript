//open/prayer/room/uhen/21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        玉衡門的練武場, 練武場上的弟子正在勤練基本的撲擊格鬥之技
        以奠定日後學習聖火教高深武學--先天乾坤功--的基礎. 只見各 
        弟子們正努力的練習著. 

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
           "north":__DIR__"14",		//練武場
	"south":__DIR__"2-door",		//練武場
	"west":__DIR__"22",		//練武場
	"east":__DIR__"20",		//練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee2" : 1,		//弟子
        "/open/prayer/npc/trainee1" : 1,		//弟子
   		
]));
        create_door("south","聖火刻紋精鋼大門", "north",DOOR_CLOSED);     
     
  setup();
}
