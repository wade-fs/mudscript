#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "走道");
	set ("long", @LONG
一個簡簡單單的走道，可以通往水靈塔和各個靈閣，周圍的景緻
也很宜人，讓你在這小小走道上稍微休息一下也是一個不錯的想法。
北邊是水靈道，你也可以感覺有陣陣的水氣傳向這裏。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor21",
	"east"	: __DIR__"manor05",
	"west"	: __DIR__"manor03",
	]));

	set("light_up", 1);
	set("outdoors", "/open/magic-manor");

  setup();
}
