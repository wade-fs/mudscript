//open/prayer/room/tangi/tangi1-5.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","石牢");
        set("long",
"此處是明教分部之一的天機門內部的石牢. 四處血跡斑斑,一定是之前所禁錮的人犯所
遺留下來的.....\n");
        set("exits", ([ /* sizeof() == 1 */
        "south":"/open/prayer/room/tangi/tangi1-6",		//地牢
        ]) );

   setup();
}
