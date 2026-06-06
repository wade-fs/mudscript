#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "廳堂內室");
	set ("long", @LONG
由聚靈正殿走了過來，這是一間小小的內室，是莊主在平時接待
來賓之餘，可以休息的地方，所以佈置也較為簡略一點，但是在這內
室中，卻明顯的可以感受到靈氣比外面的還要強，也許靈氣的來源正
是由此而來。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"south"	: __DIR__"manor01",
	]));

	set("light_up", 1);

	setup();
}
