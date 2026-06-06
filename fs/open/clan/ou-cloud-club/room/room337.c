inherit ROOM;
void create() {
	set( "short", "ω冥魔脛甲ω" );
	set( "object", ([
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount2"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file4"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file9"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount4"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10028 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room338",
		"west"      : "/open/clan/ou-cloud-club/room/room336.c",
	]) );
	set( "long", @LONG

        ω冥魔脛甲ω
        ω冥魔脛甲ω
        ω冥魔脛甲ω
        ω冥魔脛甲ω
        ω冥魔脛甲ω
        ω冥魔脛甲ω
        ω冥魔脛甲ω
        ω冥魔脛甲ω
        ω冥魔脛甲ω
        ω冥魔脛甲ω

LONG);
	setup();
	replace_program(ROOM);
}
