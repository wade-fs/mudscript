#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "封靈道");
	set ("long", @LONG
在這個地方，只覺得所有的靈氣似乎被一種無形的壓力所封鎖，
連你自身的靈氣也覺得有些不順暢，你可以感覺到前方不遠的地方似
乎傳來一股陰魂的氣息。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);
	set("no_chome", 1);

	set("exits", ([ /* sizeof() == 3 */
	"takeroad"	: "/open/magic-manor/ghost/road07",
	]));

	set("light_up", 1);

	setup();
}
