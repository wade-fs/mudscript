inherit ROOM;
void create() {
	set( "short", "ω冥魔羽靴ω" );
	set( "object", ([
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10376 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room343",
		"west"      : "/open/clan/ou-cloud-club/room/room345.c",
	]) );
	set( "long", @LONG

        ω冥魔羽靴ω
        ω冥魔羽靴ω
        ω冥魔羽靴ω
        ω冥魔羽靴ω
        ω冥魔羽靴ω
        ω冥魔羽靴ω
        ω冥魔羽靴ω
        ω冥魔羽靴ω
        ω冥魔羽靴ω
        ω冥魔羽靴ω

LONG);
	setup();
	replace_program(ROOM);
}
