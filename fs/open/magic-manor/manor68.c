#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "靈花園");
	set ("long", @LONG
靈花園中的一草一木都是世間難得一見的珍貴品種，生長在靈花
園中長年的吸收靈氣，每一花草樹木都長的青蔥翠綠、艷美無比，是
世間難得一見的花園。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor52",
	"south"	: __DIR__"manor53",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
