inherit ROOM;
void create() {
	set( "short", "ω冥魔披風ω" );
	set( "object", ([
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 11043 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room343",
	]) );
	set( "long", @LONG

        ω冥魔披風ω
        ω冥魔披風ω
        ω冥魔披風ω
        ω冥魔披風ω
        ω冥魔披風ω
        ω冥魔披風ω
        ω冥魔披風ω
        ω冥魔披風ω
        ω冥魔披風ω
        ω冥魔披風ω

LONG);
	setup();
	replace_program(ROOM);
}
