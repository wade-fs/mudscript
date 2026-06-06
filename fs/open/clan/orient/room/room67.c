inherit ROOM;
void create() {
	set( "short", "hild預定地Ⅳ" );
	set( "owner", "spicy" );
	set( "object", ([
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 11130 );
	set( "exits", ([
		"north"     : "/open/clan/orient/room/room66",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
