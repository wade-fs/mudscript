inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "廚房");
        set ("long", @LONG
一間簡陋的廚房，地上散落了一地碗具的碎片，餐桌上剩兩副較
完整的碗筷，為這個房子增加了一些人氣，其他的炊具散落於廚房的
每個角落，你還看到一個爐灶在廚房的另一角。
LONG);


        set("exits", ([ /* sizeof() == 4 */
        "west"      : __DIR__"mon01",
]));
        setup();
}
