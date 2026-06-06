//open/prayer/zhenche/22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

        在總管的書房兩旁, 站著幾位保鑣. 他們都是由總管親自
        在門內弟子中精心挑選出來的, 負責保護總管的安全, 以
        及看管總管書房內的重要物品.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "southwest":__DIR__"28",                //總管房
        "west":__DIR__"23",             //總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/paltoon1" : 1,              //保鑣
                
]));
     
  setup();
}
