//天界之城 Edit By Del
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "荒舞修羅道");
        set("long", @LONG

你正走在一道狹窄的山谷裡面，兩旁的山壁隱約可以看見刀劍的痕跡，上
面還沾了一些未乾的血漬。正當你意識到苗頭不對之際，眼前突然閃過幾
道黑影，你不禁握緊手上的武器 ...

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"sky1",
  "south" : __DIR__"sky3",
]));
        set("outdoors",1);
        set("no_transmit",1);
        setup();
        }
