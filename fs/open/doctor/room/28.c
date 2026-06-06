#include <room.h>
inherit ROOM;
void create()
{
        set("short","總管的書房");
        set("long",@LONG
這裡就是總管書房的最內部了! 銀針門的總管正在這裡辦公，看
他愁眉不展的樣子，不知道是在苦思開源節流的方法，還是如何收回扣呢?

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"24",             
        "northeast":__DIR__"22",           
        "north":__DIR__"23",       

        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/doctor/npc/general-manager" : 1,        

]));

  setup();
}


