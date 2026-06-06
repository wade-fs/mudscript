#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "轉靈閣");
	set( "build", 58 );
	set ("long", @LONG
在未進入這的門口上方掛著一塊匾額，題著「轉靈閣」三個大大
的字，讓你在未進入前即有了如此深刻的印象，而這間舍室的主人則
是聚靈八傑中的「純靈吟」。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"south"	: __DIR__"manor06",
	]));

	set("objects", ([ /* sizeof() == 2 */
	__DIR__ "npc/chun-yin" : 1,
	]));

	set("light_up", 1);

	setup();
}
