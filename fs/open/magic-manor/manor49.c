#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "山莊大門");
	set ("long", @LONG
莊嚴宏偉的大門，正豎立在你的眼前，大門的守衛並非一般的平
常人，竟然是兩隻奇型怪狀的獸人，若非是特別允許進入山莊的人，
大門的守衛是會將你攔下來的。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor40",
	"south"	: __DIR__"manor50",
	]));

	set("light_up", 1);
	set("outdoors", "/open/magic-manor");

	setup();
}
