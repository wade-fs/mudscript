//open/prayer/room/zhenche/13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

        在書房的一角, 副門主正在跟一位弟子交待注意事項! 看
        來那位弟子可能不小心犯了一點小錯. 還好副門主心腸不
        錯, 不然可就慘了.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"12",            //副門主室
        "northeast":__DIR__"10",                
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/vice-chair" : 1,           
   "/open/prayer/npc/trainee3" : 1,             //弟子
                
]));
     
  setup();
}
