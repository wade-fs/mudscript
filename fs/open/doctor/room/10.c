#include <room.h>
inherit ROOM;
void create()
{
        set("short","副門主房");
        set("long",@LONG
這裡是副門主的書房，書房內窗門几淨，書架上的書應有盡有，
有一位弟子正在整理副門主的書桌。

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"11",                
        "southwest":__DIR__"13",       
        "west":__DIR__"12",

        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/doctor/npc/trainee1" : 1,     

]));

  setup();
}


