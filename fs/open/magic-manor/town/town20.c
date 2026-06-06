#include <room.h>
#include <ansi.h>
inherit SHOP;

void create()
{
        seteuid(getuid());
        set("short", "雲風商店");
	set( "build", 3 );
        set("long", @LONG
店內擺滿了各式各樣的東西，商店回收各式各樣的東西，也有提
供交易。所以你可要看清楚了，也許正有你所需要的東西呢！你可以
看看這裏有些甚麼(list)，交易(buy)，還有估價(value)。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"town26",
]));
        set("light_up", 1);
        setup();
}
