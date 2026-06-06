//open/prayer/room/tangi/tangi1-11.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",
"此處是天機門成員討論問題的所在，也是門主發落門生與命令的地方． 廳的大小約有
百尺見方，四周陳設金壁輝煌，門徒行走絡繹不絕，可見得天機門的門徒眾多，不愧\
是聖火八天之中最大的一個支門．\n");
        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/tangi/tangi1-14",		//議事廳
        "east":"/open/prayer/room/tangi/tangi1-12",		//議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/vice-manager" : 1,		//副總管
]));

   setup();
}
