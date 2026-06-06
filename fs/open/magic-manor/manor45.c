#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "走廊");
	set ("long", @LONG
走進這裏，走廊上有三個門可以通往三間不同的廂房，走廊上佈
置簡單並沒有什麼太起眼的擺設，整齊、清潔是眼前唯一的寫照。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor46",
	"south"	: __DIR__"manor48",
	"east"	: __DIR__"manor66",
	"west"	: __DIR__"manor47",
	]));

	set("light_up", 1);

	setup();
}
