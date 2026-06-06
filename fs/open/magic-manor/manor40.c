#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "穿堂");
	set ("long", @LONG
從大門走進這個穿堂裏，光線充足，穿堂東西方個有一條走道，
是來訪的客人休息的地方，一直往前方走去則有一條通道是可以進入
山莊裏面的通道。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor39",
	"south"	: __DIR__"manor49",
	"east"	: __DIR__"manor67",
	"west"	: __DIR__"manor66",
	]));

	set("light_up", 1);

	setup();
}
