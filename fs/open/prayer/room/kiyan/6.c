//open/prayer/room/kiyan/6.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

	在廳上可以見到許多較高職位的幹部，一個個面目嚴肅
	站在那裡，等候著向門主報告份內的職責，以便能讓門
	主適時的處理掉棘手的問題!!廳上站立者是教頭．

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"3",		//右護法
        "west":__DIR__"7",		//議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
	"/open/prayer/npc/general" : 1,		//教頭
	"/open/prayer/npc/man5" : 1,		
	]));

	setup();
}
