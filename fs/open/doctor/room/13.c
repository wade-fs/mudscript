#include <room.h>
inherit ROOM;
void create()
{
        set("short","副門主房");
        set("long",@LONG
在書房的一角，副門主正在跟一位弟子交待注意事項，看來那位弟
子可能不小心犯了一點小錯，還好副門主心腸不錯，不然可就慘了，被
罰針扎可不是好玩的。

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"12",            
        "northeast":__DIR__"10",

        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/doctor/npc/vice-chair" : 1,
   "/open/doctor/npc/trainee2" : 1,    

]));

  setup();
}


