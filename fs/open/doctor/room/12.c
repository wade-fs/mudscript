#include <room.h>
inherit ROOM;
void create()
{
        set("short","副門主房");
        set("long",@LONG
一進入辦公房，可以很顯地感受到一股緊張忙碌的氣氛，有兩個
弟子正在整理病人的資料，準備送給副門主過目。

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"11",            
        "south":__DIR__"13",            
        "west":__DIR__"14",           
        "east":__DIR__"10",          

        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/doctor/npc/trainee1" : 1,          
   "/open/doctor/npc/trainee2" : 1,      

]));

  setup();
}


