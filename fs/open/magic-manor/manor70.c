#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "庭園小橋");
	set ("long", @LONG
一座小型的石橋，石橋下可以聽到潺潺的流水聲，流水中還可以
見到綿鯉悠閒的在水中游著，石橋是大理石建材，雖然歷經歲月的摧
殘，仍不減石橋風彩。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor71",
	"south"	: __DIR__"manor69",
	"east"	: __DIR__"manor74",
	"west"	: __DIR__"manor73",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
