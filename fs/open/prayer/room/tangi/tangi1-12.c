//open/prayer/room/tangi/tangi1-12.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",
"此處是天機門成員討論問題的所在，也是門主發落門生與命令的地方． 廳的大小
約有百尺見方，四周陳設金壁輝煌，門徒行走絡繹不絕，可見得天機門的門徒眾多
，不愧\是聖火八天之中最大的一個支門．\n");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/tangi/tangi1",			//門主
        "south":"/open/prayer/room/tangi/tangi1-15",		//議事廳
        "east":"/open/prayer/room/tangi/tangi1-13",		//議事廳
        "west":"/open/prayer/room/tangi/tangi1-11",		//議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/servant" : 1,		//小茶僮
]));

   setup();
}
