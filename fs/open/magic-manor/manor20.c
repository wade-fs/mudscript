#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "左靈火舍");
	set( "build", 1 );
	set ("long", @LONG
火舍中充滿了一股奇異的靈氣，靈氣中隱隱的含著火的氣息，在
火舍的裏側正上方一塊匾額題著「左靈火舍」，而且還是莊主親自題
字，足以顯得對此舍的主人之重視，透過火舍窗戶向外看過去可以隱
隱看到一個繚繞著漫天火焰的火靈塔。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"south"	: __DIR__"manor07",
	]));

	set("objects", ([ /* sizeof() == 2 */
	__DIR__ "npc/left-linr" : 1,
	]));

	set("light_up", 1);

	setup();
}
