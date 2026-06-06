#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIR"火靈塔"NOR);
	set( "build", 5 );
	set ("long", @LONG
火靈塔的周圍遍滿了火焰的包圍，熾熱的火氣不時的向你這邊襲
來，若非功力深厚的人，將承受不住這樣大的火氣侵襲，此塔中佈滿
了火焰，若不能尋找到一個克制火的寶物，將有可能在裏面被火焰活
活的給燒死。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"south"	: __DIR__"manor22",
	"enter"	: __DIR__"fire/fire01",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
