#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "庭園");
	set ("long", @LONG
小小的庭園，佈滿各式庭園造景，有小山，小橋，流水，看上去
的風景是如此的美麗，似是來到一處人間仙境般，在造景的小山
後方隱隱可見一個幽暗的小洞，卻不知會通往何處。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"west"	: __DIR__"manor70",
	"enter" : "/open/zombie_hole/enter",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
