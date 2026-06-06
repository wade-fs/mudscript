inherit ROOM;
void create() {
	set( "short", "幸運草環室" );
	set( "object", ([
		"amount9"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room310",
		"south"     : "/open/clan/13_luck/room/room305",
	]) );
	set( "build", 10146 );
	set( "light_up", 1 );
	set( "long", @LONG

    這這，是那個傳說中小東邪郭襄手中的幸運草環嗎？此人的掌法得
到東邪黃藥師的真傳，一掌三四千都不誇張，加上變態的劍法，難怪是
free mob中的狠角色，加上那機車的倚天劍，武器都會被打壞，所以幸
運草環來之不易，希望愛惜使用。

LONG);
	setup();
	replace_program(ROOM);
}
