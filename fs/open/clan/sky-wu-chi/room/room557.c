inherit ROOM;
void create() {
	set( "short", "儀器室" );
	set( "object", ([
		"amount1"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 18,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/obj/sun-heart",
		"file3"    : "/open/ping/obj/poison_pill",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
	]) );
	set( "light_up", 1 );
	set( "build", 10117 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room555.c",
		"north"     : "/open/clan/sky-wu-chi/room/room622",
	]) );
	set( "long", @LONG
以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,
以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,
以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,
以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,
以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,
LONG);
	setup();
	replace_program(ROOM);
}
