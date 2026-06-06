//open/prayer/room/tangi/tangi1-1.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","門主的書房");
        set("long",@LONG

	此處是天機門門主所屬的書房，只見四周的書櫃都裝滿了詩
	集與文物卷軸，可見得門主司馬錦對於文學的品嚐是非常重
	視的．同時這裡也是天機門門生的秘密聚會之地!!非聖火教
	者是不能進入的!! 

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "south":"/open/prayer/room/tangi/tangi1",		//門主
        ]) );
        set("no_fight", 0);
        set("light_up", 1);

   setup();
}



