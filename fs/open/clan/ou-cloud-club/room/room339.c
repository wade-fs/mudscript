inherit ROOM;
void create() {
	set( "short", "ω冥魔指套ω" );
	set( "object", ([
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount1"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount4"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10123 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room340",
		"west"      : "/open/clan/ou-cloud-club/room/room338",
	]) );
	set( "long", @LONG

        ω冥魔指套ω
        ω冥魔指套ω
        ω冥魔指套ω
        ω冥魔指套ω
        ω冥魔指套ω
        ω冥魔指套ω
        ω冥魔指套ω
        ω冥魔指套ω
        ω冥魔指套ω
        ω冥魔指套ω

LONG);
	setup();
	replace_program(ROOM);
}
