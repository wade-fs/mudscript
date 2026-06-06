#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIY + "聚靈池" + NOR);
	set ("long", @LONG
聚靈池，是聚靈山莊的一個奇特的池子，山莊飄散出來的靈氣大
都會飄往這裏，最後被聚靈池吸收，在聚靈池中心，聚集著強大的靈
氣，愈往池中心，靈氣愈是強烈，並聚成五彩靈光，在池中來來回回
的穿越奔騰，剎是好看。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor68",
	]));

	set("light_up", 1);
	set("outdoors", "/open/magic-manor");

	setup();
}
