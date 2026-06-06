#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "三轉靈道");
	set( "build", 2 );
	set ("long", @LONG
愈至這裏，愈覺得兇險的感覺湧上了心頭，前方入目的是三條不
同的道路，從每條道路的那頭還不時的飄來不同色的靈光，靈光中還
夾帶著些許的殺傷力。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor64",
	"south"	: __DIR__"manor60",
	"east"	: __DIR__"manor62",
	"west"	: __DIR__"manor58",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
