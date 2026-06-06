#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "小徑");
	set( "build", 1 );
	set ("long", @LONG
由小徑的那一頭走過來，似乎又來到了另一境地，前方只剩一小
條的路徑，前方的路途似乎帶有極大的兇險，在此地的你也有少許的
感覺了。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"east"	: __DIR__"manor59",
	"west"	: __DIR__"manor54",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
