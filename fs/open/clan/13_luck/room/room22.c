inherit ROOM;
void create() {
	set( "short", "青龍齊天" );
	set( "owner", "mad" );
	set( "object", ([
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/ping/obj/ring-2",
		"amount5"  : 2,
		"file10"   : "/open/soldier/obj/hit",
		"amount4"  : 146,
		"amount7"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount10" : 1,
		"file5"    : "/obj/stone/jiao",
		"amount8"  : 1,
		"file4"    : "/obj/stone/powder",
		"amount1"  : 8,
		"file7"    : "/daemon/class/fighter/figring",
		"amount6"  : 1,
		"file2"    : "/open/mon/obj/mon_item",
		"amount2"  : 1,
		"file9"    : "/autoload/killer/reko_sword",
		"file1"    : "/obj/stone/suipian",
		"amount3"  : 1,
	]) );
	set( "build", 10245 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room23",
		"down"      : "/open/clan/13_luck/room/room21.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    一踏上樓梯的最後一格你有種如釋重負的感覺，覺的剛剛的辛苦都
值的了，因為你即將看到主宰十三吉祥之主，你心裡有一點的緊張，但
興奮的心情更尤勝於他，當然如果你在這就回頭，你就會後悔一生，往
前走就是齊天道。

LONG);
	setup();
	replace_program(ROOM);
}
