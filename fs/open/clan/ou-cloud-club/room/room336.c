inherit ROOM;
void create() {
	set( "short", "ω冥魔足環ω" );
	set( "object", ([
		"amount5"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file2"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount8"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file9"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount4"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10042 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room337",
		"west"      : "/open/clan/ou-cloud-club/room/room335.c",
	]) );
	set( "long", @LONG

        ω冥魔足環ω
        ω冥魔足環ω
        ω冥魔足環ω
        ω冥魔足環ω
        ω冥魔足環ω
        ω冥魔足環ω
        ω冥魔足環ω
        ω冥魔足環ω
        ω冥魔足環ω
        ω冥魔足環ω

LONG);
	setup();
	replace_program(ROOM);
}
