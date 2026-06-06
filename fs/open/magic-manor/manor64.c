#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "土靈道");
	set( "build", 3 );
	set ("long", @LONG
一條通往土靈塔必需要經過的道路，土靈塔那裏傳來的土之氣息
已經愈來愈濃厚，若非有一番修為的人來到此，也許會抵受不住那飛
沙走石的猛烈侵襲。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor65",
	"south"	: __DIR__"manor59",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
