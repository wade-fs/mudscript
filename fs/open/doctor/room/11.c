#include <room.h>
inherit ROOM;
void create()
{
        set("short","副門主房");
        set("long",@LONG
銀針門每天公務都很繁忙，因此有幾個弟子每天都要來幫忙，不過
看他們專心工作的情形，好像一點抱怨也沒有，完全服從上級的指示。

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"12",          
        "southeast":__DIR__"10",

        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/doctor/npc/trainee2" : 1,            
   "/open/doctor/npc/trainee1" : 1,  

]));

  setup();
}

