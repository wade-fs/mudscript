inherit ROOM;
void create() {
	set( "short", "木行區" );
	set( "object", ([
		"amount7"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10089 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room622",
	]) );
	set( "long", @LONG
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
LONG);
	setup();
	replace_program(ROOM);
}
