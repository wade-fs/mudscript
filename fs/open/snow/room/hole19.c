#include <room.h>

inherit ROOM;

void create()
{
           set("short","洞穴");
          set("long","洞穴第二層,由於景象都差不多,所以在沒有完整的地圖概念之前,最好不要誤闖此處。\n");

        set("exits", ([
          "west":__DIR__"hole18",
          "east":__DIR__"hole14",
       ]) );
       set("objects", ([ /* sizeof() == 3 */
       "/open/snow/npc/2_banditking" :1
       ]) );
        setup();
}
