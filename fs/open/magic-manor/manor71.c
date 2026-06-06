#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "山莊走道");
	set( "build", 1 );
	set ("long", @LONG
再往前去就是山莊的內部了，山莊的走道兩旁仍是佈滿了奇異的
藤蔓，開的花散發著奇異幽香，夾道的輕輕微風吹來，使整個走道上
佈滿著淡淡幽香，令人精神為之一震。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor72",
	"south"	: __DIR__"manor70",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
