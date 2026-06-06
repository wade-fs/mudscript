#include <room.h>
inherit ROOM;
void create()
{
        set("short","總管的書房");
        set("long",@LONG
銀針門總管的書房，這裡是總管處理門務的地方，總管是門主以下與
副門主同一職等的幹部，專門負責門內事務的處理。

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"18",          
        "south":__DIR__"28",          
        "east":__DIR__"22",           
        "west":__DIR__"24",        

        ]) );
        set("no_fight", 0);
        set("light_up", 1);


  setup();
}


