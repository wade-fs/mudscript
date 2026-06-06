//open/prayer/room/tangi/tangi1-31.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",
"此處是明教分部之一的天機門的練武場,練武場上的弟子正在勤練鎮教武學--
先天乾坤功\的基礎功\夫.往北是天機門的大廳,往南則是天機門的大門(open door). \n");

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/tangi/tangi1-26",		//練武場
	"south":"/open/prayer/room/tangi/tangi1-34",		//練武場
	"east":"/open/prayer/room/tangi/tangi1-32",		//練武場
        "west":"/open/prayer/room/tangi/tangi1-30",		//練武場
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4.c" : 2,		//弟子
   		
]));
     set("light_up", 1);
     create_door("south","聖火刻紋精鋼大門","north",DOOR_CLOSED);
  setup();
}
