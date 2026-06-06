#include <room.h>
inherit ROOM;
void create()
{
        set("short", "客房");
        set("long", @LONG

    一間寬敞舒適的客房，一張圓桌上正擺著剛沏好的茶，煦和的陽
光從窗口照到地板上，多麼幽雅的環境，的確是一間適合招待遠客下
榻，看桌上的茶正熱著，不知道此地來了哪位貴賓？

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"6",            
        "east":__DIR__"8",          
        ]) );
        set("light_up", 1);
        set("objects", ([ /* sizeof() == 1 */
        "/open/doctor/npc/chan" : 1,
]));

   setup();
}


