#include <room.h>
inherit ROOM;
void create()
{
        set("short","練武場");
        set("long",@LONG
在練武場的東北角，有兩個弟子正在沙盤推演，似乎對剛才所
學的步法有所領悟的樣子。

LONG);

        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"14",            
        "south":__DIR__"19",            
        "west":__DIR__"16",             

        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/doctor/npc/trainee1" : 1,              
  "/open/doctor/npc/trainee2" : 1,            

]));

  setup();
}


