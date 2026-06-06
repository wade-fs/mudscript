#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "山莊走道");
	set ("long", @LONG
山莊走道旁種滿了一種奇異的藤蔓，蔓延了道路的兩側，開的花
散發著奇異幽香，夾道的輕輕微風吹來，使整個走道上佈滿著淡淡幽
香，令人精神為之一震。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor34",
	"south"	: __DIR__"manor38",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
