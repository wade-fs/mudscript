//open/prayer/room/zhenche/24.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

        因為總管不喜歡男性進入他的書房, 所以他挑選的保鑣也
        都是女性. 不過可別小看她們喔! 打起架來可是一點也不
        輸給男性喔!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "southeast":__DIR__"28",        //總管房
        "east":__DIR__"23",             //總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/paltoon1" : 1,              //保鑣
  "/open/prayer/npc/paltoon2" : 1,              //保鑣
                
]));
     
  setup();
}
