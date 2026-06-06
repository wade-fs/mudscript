//open/prayer/room/tangi/tangi1-16.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",
"此處是天機門成員討論問題的所在．拳師是負責教授與實際督導門內弟子武學的
指導，每個月都必須針對弟子的練功\狀況向門主報告．\n");
        set("exits", ([ /* sizeof() == 2 */
        "north":"/open/prayer/room/tangi/tangi1-13",		//議事廳
        "west":"/open/prayer/room/tangi/tangi1-15",		//議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/puncher" : 1,		//拳師
]));

   setup();
}
