#include <room.h>
inherit ROOM;
void create()
{
        set("short","總管的書房");
        set("long",@LONG
在總管的書房兩旁，站著幾位保鑣，他們都是由總管親自在門內
弟子中精心挑選出來的，負責保護總管的安全，以及看管總管書房內
的重要物品。

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "southwest":__DIR__"28",        
        "west":__DIR__"23",           

        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/doctor/npc/paltoon" : 1,         

]));

  setup();
}


