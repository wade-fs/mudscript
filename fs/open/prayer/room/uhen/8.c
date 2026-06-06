//open/prayer/room/uhen/8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

	在廳上可以見到許多較高職位的門徒，一個個面目嚴肅
	站在那裡，等候著向門主報告份內的職責，以便能讓門
	主適時的處理掉棘手的問題．

LONG);
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"5",		//議事廳
        "east":__DIR__"7",		//議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/major-officer" : 1,		
]));

   setup();
}
