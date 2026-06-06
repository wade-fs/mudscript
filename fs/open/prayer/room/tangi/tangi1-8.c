//open/prayer/room/tangi/tangi1-8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","石牢");
        set("long",@LONG
此處是明教分部之一的天機門內部的石牢.這位犯人是一位天機門的弟子,看他傷痕累累,
一定是遭受到不少的虐待吧!!不過他那個樣子真是讓人有股想凌虐他的衝動!! 
LONG);
        set("exits", ([ /* sizeof() == 1 */
        "south":"/open/prayer/room/tangi/tangi1-9",		//地牢
        ]) );
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/criminal2" : 1,		//人犯
        ]) );

   setup();
}
