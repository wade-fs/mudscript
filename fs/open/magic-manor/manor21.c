#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "水靈道");
	set ("long", @LONG
一條通往水靈塔必需要經過的道路，水靈塔那裏傳來的水之氣息
已經愈來愈濃厚，若非有一番修為的人來到此，也許會抵受不住
那水氣的猛烈侵襲。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor24",
	"south"	: __DIR__"manor04",
	]));

	set("light_up", 1);
	set("outdoors", "/open/magic-manor");

	setup();
}
