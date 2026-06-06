//open/prayer/room/zhenche/28.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

        這裡就是總管書房的最內部了! 陣勢門的總管正在這裡
        辦公. 看他愁眉不展的樣子, 不知道是在苦思開源節流
        的方法, 還是如何收回扣呢?

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"24",                //總管房
        "northeast":__DIR__"22",                //總管房
        "north":__DIR__"23",            //總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/general-manager" : 1,         //總管
                
]));
     
  setup();
}
