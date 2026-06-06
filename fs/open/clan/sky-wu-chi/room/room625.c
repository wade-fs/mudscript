inherit ROOM;
void create() {
	set( "short", "土行二" );
	set( "object", ([
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
	]) );
	set( "build", 10037 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room654",
		"west"      : "/open/clan/sky-wu-chi/room/room624.c",
		"north"     : "/open/clan/sky-wu-chi/room/room626.c",
		"east"      : "/open/clan/sky-wu-chi/room/room653.c",
	]) );
	set( "long", @LONG
啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦
啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦
啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦
啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦
LONG);
	setup();
	replace_program(ROOM);
}
