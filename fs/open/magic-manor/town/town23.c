#include <room.h>
#include <ansi.h>
inherit BANK;

void create()
{
        seteuid(getuid());
        set("short", "雲風錢莊");
        set("long", @LONG
這是雲風鎮內一家頗具信譽的錢莊，你可以放心的在這裏存錢和
提錢，也可以將身上的零錢，化零為整，是一個很方便的地方，幫助
你解決一些金錢的問題。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"town29",
]));
        set("light_up", 1);
        setup();
}
