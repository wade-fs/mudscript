#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "靈舍走廊");
	set( "build", 5 );
	set ("long", @LONG
經過穿堂到達靈舍走廊，這裏是到達火靈塔必經之路，北邊的方
向是通往左靈火舍，經過靈舍走廊可以抵達各個舍室，走出靈舍可以
到達一個走道，靈舍的走廊傳來的盡是靈舍中充斥的靈氣，令你想跓
足在這裏享受那靈氣浸縈的感覺。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor20",
	"east"	: __DIR__"manor02",
	"west"	: __DIR__"manor08",
	]));

	set("light_up", 1);

	setup();
}
