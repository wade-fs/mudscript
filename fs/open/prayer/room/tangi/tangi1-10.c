//open/prayer/room/tangi/tangi1-10.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","石牢");
        set("long",
"天機門內部的石牢，主要都是禁錮一些犯了教規的門徒，當然也會有一些是屬下自己
從外面抓回來可疑的奸細．這裡正好有一位是從中原來的人士，因為被懷疑所以被
抓來這裡 ．\n");
        set("exits", ([ /* sizeof() == 1 */
        "north":"/open/prayer/room/tangi/tangi1-9",		//地牢
        ]) );
       set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/criminal" : 1,		//人犯
]));

   setup();
}
