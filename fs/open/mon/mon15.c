inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "小平台");
        set ("long", @LONG
從平原小徑走過來，這個小平台的面積不大，平台邊有兩棵樹，
伴隨著些許青蔥的綠草，冷冷的山風似乎傳達不到這個地方，陣陣
的暖意卻慢慢的由心中升起。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "west"     : __DIR__"mon14",
]));
        setup();
}

