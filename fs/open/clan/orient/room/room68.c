inherit ROOM;
void create() {
	set( "short", "hild預定地Ⅲ" );
	set( "owner", "spicy" );
	set( "object", ([
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
	]) );
	set( "build", 10196 );
	set( "exits", ([
		"south"     : "/open/clan/orient/room/room66",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
