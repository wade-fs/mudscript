//open/prayer/room/tanchun/9.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

	在廳上站立著許多較高職位的門徒，他們一個個心事重重的樣子
	，等候著向門主報告份內的職責，以便能讓門主適時的處理掉棘
	手的問題．

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"6",		//議事廳
        "east":__DIR__"8",		//議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/vice-manager" : 1,		
]));

   setup();
}
