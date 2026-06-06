inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "上峰坡");
	set( "build", 14 );
        set ("long", @LONG
要登上長白山的頂端，這是一個重要的通道，但卻通往不同的三
個峰，東邊是通往「山隨峰」，北邊是通往「白懷峰」，西邊是通往
「長情峰」。另外還有一條路是通往南邊的路，卻不知要通往何方。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "east"        : __DIR__"mon39",
        "north"       : __DIR__"mon43",
        "west"        : __DIR__"mon44",
        "down"        : __DIR__"mon37",
        "southdown"   : __DIR__"mon54",
]));
        setup();
}
