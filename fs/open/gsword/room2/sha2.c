#include <ansi.h>
inherit ROOM;
void create()
{
   set("short", HIW"仙劍峽谷"NOR);
   set("long", @LONG
一個雜草叢生的峽谷.四周山壁聳立..看起來似乎無法離開此處...
由前面的走道..我想你只能向前走了.。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
 "north":"/open/gsword/room2/sun5",
 "south":"/open/gsword/room2/sha1",

]));
        set("light_up",1);
        set("no_transmit", 1);
        setup();
}

