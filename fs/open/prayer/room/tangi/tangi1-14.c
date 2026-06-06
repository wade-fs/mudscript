//open/prayer/room/tangi/tangi1-14.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",
"副總教頭面目嚴肅站在那裡，等候著向門主報告份內的職責，看他眉頭深鎖可能
是門內的保安出了問題了！上次刺客潛入的事件到現在還沒有解決．難怪他心神
緊張!\n");
        set("exits", ([ /* sizeof() == 2 */
        "north":"/open/prayer/room/tangi/tangi1-11",		//議事廳
        "east":"/open/prayer/room/tangi/tangi1-15",		//議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);  
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/major-officer" : 1,		//副總教頭
]));

   setup();
}
