inherit ROOM;
void create() {
	set( "short", "土行一" );
	set( "object", ([
		"amount3"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file2"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file9"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/obj/gift/unknowdan",
		"amount2"  : 31,
		"amount9"  : 1,
	]) );
	set( "build", 10039 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room622",
		"east"      : "/open/clan/sky-wu-chi/room/room625",
	]) );
	set( "long", @LONG
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補

LONG);
	setup();
	replace_program(ROOM);
}
