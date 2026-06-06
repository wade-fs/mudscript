#include <room.h>

 inherit ROOM;

 void create()
{
      
        set("short", "岩穴");
        set("long", @LONG
這兒是巖穴的內部，一道光線由上面宣洩而下，照亮了整個洞穴，原來這巖穴
的上面透出一個小孔，使得陽光雨水得以進入，也因為如此，這兒長出了一些
果樹之類了植物。
LONG
        );

        set("exits", ([
"south":__DIR__"hole"
        ]) );
setup();

}
