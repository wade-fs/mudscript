//open/prayer/room/tanchun/26.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	天權門的練武場, 練武場上的弟子正在練掌法. 看看地上的掌
	印, 雖然先天乾坤功的威力無儔!!不過在初學者的手上使將起
	來卻還是缺少那麼一點霸氣!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"20",		//練武場
	"south":__DIR__"2-door",	//練武場
	"west":__DIR__"27",		//練武場
	"east":__DIR__"25",		//練武場
 
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
