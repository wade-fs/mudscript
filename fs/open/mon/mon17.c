inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "碎石坡");
        set ("long", @LONG
愈往前走，地面仍舊滿怖了碎石，景色依舊，在兩旁草木更顯枯
黃稀少，空氣中的水氣也愈來愈濃，冷冷的風疾疾的吹，寒冷的氣息
也一點一滴的鑽進你的體內，讓你摸不清前方的路還有多遠。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "northup"    : __DIR__"mon18",
        "eastdown"   : __DIR__"mon16",
]));
        setup();
}

