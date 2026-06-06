#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
	set ("short", "穿堂");
	set( "build", 2 );
	set ("long", @LONG
藉由穿堂往北方可以通達聚靈山莊的正殿，西邊可以通達聚靈山
莊的各個舍室，而東邊的方向則可以通往各個閣室，是一個極為重要
的穿堂，因此守衛也比較森嚴些。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor01",
	"south"	: __DIR__"manor72",
	"east"	: __DIR__"manor03",
	"west"	: __DIR__"manor07",
	]));

	set("item_desc", ([ /* sizeof() == 1 */
	"south" : (: look_door,     "south" :),
	]));

	create_door("south",HIR + "鴻元聚靈門" + NOR,"north",DOOR_CLOSED);
	set("light_up", 1);

	setup();

}
