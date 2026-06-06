#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "廂房走道");
	set ("long", @LONG
簡僕的走道，走道旁擺著幾個盆栽，讓走道看來較具生氣，是通
往廂房走道，在走道的不遠處即可看到一間若大的屋子，屋子是百年
沉香木所建造，風格真是古色古香。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"east"	: __DIR__"manor40",
	"west"	: __DIR__"manor45",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
