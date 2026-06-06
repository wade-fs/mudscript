#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "小徑");
	set( "build", 1 );
	set ("long", @LONG
含風亭走過來，路徑一轉，景緻一變，已是一條小徑在眼前，小
徑的足跡並不明顯，似是很少有人來過，小徑的北方有一條更小的幽
徑，不知是通往何方，東方則是另外一段小徑的路。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor55",
	"east"	: __DIR__"manor58",
	"west"	: __DIR__"manor51",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
