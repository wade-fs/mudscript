//open/prayer/room/tangi/tangi1-13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",
"在廳上可以見到許\多較高職位的門徒，一個個面目嚴肅站在那裡，等候著向門主報告
份內的職責，以便能讓門主適時的處理掉棘手的問題．教頭可能是沒有什麼問題吧！
看他一付很輕鬆的樣子．\n");
        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/tangi/tangi1-16",		//議事廳
        "west":"/open/prayer/room/tangi/tangi1-12",		//議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/general" : 1,		//教頭
]));

   setup();
}
