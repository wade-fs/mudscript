#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "幽徑");
	set ("long", @LONG
幽幽的小徑，帶著微弱的光線，幽徑的光線盡被兩旁高大的古木
給遮光了，在此微弱的光芒下，更添了幾分幽靜的氣息。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor57",
	"south"	: __DIR__"manor55",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
