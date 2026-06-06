#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "山莊走道");
	set( "build", 1 );
	set ("long", @LONG
經過了練武廣場，又來到一處山莊必經的走道，山莊的走道兩旁
仍是佈滿了奇異的藤蔓，開的花散發著奇異幽香，夾道的輕輕微風吹
來，使整個走道上佈滿著淡淡幽香，令人精神為之一震。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor70",
	"south"	: __DIR__"manor33",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
