#include <room.h>
inherit ROOM;
void create()
{
        set("short","總管的書房");
        set("long",@LONG
因為總管不喜歡男性進入他的書房，所以他挑選的保鑣也都是女性
，不過可別小看她們喔，打起架來可是一點也不輸給男性喔。

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "southeast":__DIR__"28",       
        "east":__DIR__"23",         

        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/doctor/npc/paltoon" : 2,                        

]));

  setup();
}


