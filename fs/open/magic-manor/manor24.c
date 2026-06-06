#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIC + "水靈塔" + NOR);
	set ("long", @LONG
水靈塔的周圍遍滿了冰氣的包圍，極冷的水氣化為萬般的冰氣並
不時的向你這邊襲來，若非功力深厚的人，將承受不住這樣大的冰氣
侵襲，此塔中佈滿了冰氣，若不能尋找到一個克制水的寶物，將有可
能在裏面被冰氣活活的給凍死。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"south"	: __DIR__"manor21",
	"enter"	: __DIR__"water/water01",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
