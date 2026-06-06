#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "走廊");
	set( "build", 276 );
	set ("long", @LONG
靈閣外的走廊，南北各通往一間靈閣，南邊的是葵靈閣，北邊的
是轉靈閣，往西邊可以通往另一段走廊，走廊兩旁的景物樸實簡單卻
又不失高雅。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor17",
	"south"	: __DIR__"manor16",
	"west"	: __DIR__"manor05",
	]));

	set("light_up", 1);

	setup();
}
