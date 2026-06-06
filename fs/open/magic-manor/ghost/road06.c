#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "封靈道–嫵");
	set ("long", @LONG
所有的靈力在這地方似乎都有點被壓抑的感覺，站在這裏守護道
路的人，似乎是你所熟悉的面孔，但總是說不出是那裏不一樣，正在
你還傻在那裏的時候，陣陣的寒氣已經向你這邊壓迫過來了!!

LONG);

	set("no_auc", 1);
	set("no_transmit", 1);
	set("no_chome", 1);

	set("exits", ([ /* sizeof() == 3 */
	"out"	: "/open/magic-manor/ghost/rest06",
	]));


	set("objects", ([ /* sizeof() == 3 */
	__DIR__"npc/funchin-sen" : 1,
	]));

	set("light_up", 1);

	setup();
}
