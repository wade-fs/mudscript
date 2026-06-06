//open/prayer/room/uhen/6.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

	在廳上可以見到許多較高職位的門徒，一個個面目嚴
	肅站在那裡，等候著向門主報告份內的職責，以便能
	讓門主適時的處理掉棘手的問題．教頭可能是沒有什
	麼問題吧！看他一付很輕鬆的樣子．

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"3",		//右護法
        "west":__DIR__"7",		//議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/general" : 1,		//教頭
]));

   setup();
}
