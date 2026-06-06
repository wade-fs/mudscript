//open/prayer/room/tanchun/5.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

	在廳上可以見到許多較高職位的門徒，一個個面目嚴肅站在那
	裡，等候著向門主報告份內的職責，以便能讓門主適時的處理
	掉棘手的問題．

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"2",		//議事廳
        "south":__DIR__"8",		//議事廳
        "east":__DIR__"4",		//議事廳
        "west":__DIR__"6",		//議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
   setup();
}
