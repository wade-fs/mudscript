#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "聖心舍");
	set( "build", 1 );
	set ("long", @LONG
在未進入這的門口上方掛著一塊匾額，題著「聖心舍」三個大大
的字，讓你在未進入前即有了如此深刻的印象，而這間舍室的主人則
是聚靈八傑中的「凌方真」。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor10",
	]));

	set("objects", ([ /* sizeof() == 2 */
	__DIR__ "npc/linfun-jen" : 1,
	]));

	set("light_up", 1);

	setup();
}
