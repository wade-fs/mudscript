#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "走廊");
	set( "build", 227 );
	set ("long", @LONG
靈閣外的走廊，南北各通往一間靈閣，南邊的是天靈閣，北邊的
是齊靈閣，再往東邊可以通往另一段走廊，走廊兩旁的景物樸實簡單
卻又不失高雅。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor18",
	"south"	: __DIR__"manor15",
	"east"	: __DIR__"manor06",
	"west"	: __DIR__"manor04",
	]));

	set("light_up", 1);

	setup();
}
