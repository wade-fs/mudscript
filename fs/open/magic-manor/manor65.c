#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", YEL"土靈塔"NOR);
	set( "build", 1 );
	set ("long", @LONG
土靈塔的周圍遍滿了土牆的包圍，若有靈性的土牆會朝有生命的
物體移動，並將他們重重包圍，直至生物的生命消逝才罷休，此塔中
佈滿的土牆，若不能尋找到一個克制土的寶物，將有可能被裏面的飛
沙走石給淹沒。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"south"	: __DIR__"manor64",
	"enter"	: __DIR__"soil/soil01",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
