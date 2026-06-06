#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
	set ("short", "莊院大門");
	set ("long", @LONG
到正廳的必經之路，一扇若大的紅色大門豎立眼前，這扇大門是
採千年寒鐵所鑄造而成，，平時是可以任人自由開啟的，若非有點內
功底子的人是很難推開這扇門的。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor02",
	"south"	: __DIR__"manor71",
	]));

	create_door("north",HIR"鴻元聚靈門"NOR,"south",DOOR_CLOSED);
	set("light_up", 1);

	setup();

}
