inherit ROOM;
void create() {
	set( "short", "金行一" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10107 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room648",
		"west"      : "/open/clan/sky-wu-chi/room/room645.c",
		"north"     : "/open/clan/sky-wu-chi/room/room646.c",
		"east"      : "/open/clan/sky-wu-chi/room/room642.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
懶的寫....................................................
懶的寫....................................................
懶的寫....................................................
懶的寫....................................................
懶的寫....................................................
LONG);
	setup();
	replace_program(ROOM);
}
