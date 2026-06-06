//open/prayer/room/tangi/tangi1-23.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",
"天機門的走廊，走廊的支柱同樣是以檜木造成的，與廊頂的整體造型非常搭配，
西邊是往練武場．南邊是往副門主的辦公房．\n");

        set("outdoors", "/u/r/rence");
        set("no_fight", 0);
        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/tangi/tangi1-28",		//走廊
        "west":"/open/prayer/room/tangi/tangi1-22",		//走廊
       
        ]) );
     
  setup();
}
