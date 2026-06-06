//__DIR__"17.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

	玉衡門總管的書房, 總管是門主以下與副門主同一職等的
        幹部. 負責門內事務的處理. 由於總管不太喜歡別人來打
        擾. 所以在門口派了一個保鑣來過慮一些閒雜人物的進出

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"16",		//總管房
        "south":__DIR__"18",		//總管房
        "east":__DIR__"15",		//總管房
        "west":__DIR__"19",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/paltoon2" : 1,		//保鑣
   		
]));
     
  setup();
}
