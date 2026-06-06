//open/prayer/room/garden3.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	    此處是聖火教總壇的花園，也是收集珍奇
	野獸的地方．雖然教主並沒有明令禁止教眾進
	來此地，不過為了自身的生命安全，陌生的地
	方還是不要亂闖的好呀!!眼前的這隻怪物正張
	牙舞爪的像你撒嬌哩!!
 
LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/garden7",		//花園
        "south":"/open/prayer/room/garden1",		//  "
        "east":"/open/prayer/room/garden2",		// "
        "west":"/open/prayer/room/garden4",		// "
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/crab-ox" : 1,		
]));
   create_door("south","木製柵欄","north",DOOR_CLOSED);
   setup();
}
