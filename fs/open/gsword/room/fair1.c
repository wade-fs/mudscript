#include <room.h>

 inherit ROOM;

 void create()
{
      
        set("short", "林中空地");
        set("long", @LONG
不知為什麼在茂密的樹林中，這兒竟然寸草不生，使勁的朝地上踏去,發現
這兒的土地堅硬的很，也難怪植物難以在這生根了。
LONG
        );

        set("exits", ([
"west":__DIR__"plain6",
"south":__DIR__"plain4",
"east":__DIR__"fair"
        ]) );
setup();

}
