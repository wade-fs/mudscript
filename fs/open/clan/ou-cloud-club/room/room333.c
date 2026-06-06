inherit ROOM;
void create() {
	set( "short", "ω冥魔腰帶ω" );
	set( "object", ([
		"file8"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount8"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount6"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount3"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount5"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
	]) );
	set( "owner", "enter" );
	set( "light_up", 1 );
	set( "build", 10853 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room334",
		"west"      : "/open/clan/ou-cloud-club/room/room332",
	]) );
	set( "long", @LONG

        ω冥魔腰帶ω
        ω冥魔腰帶ω
        ω冥魔腰帶ω
        ω冥魔腰帶ω
        ω冥魔腰帶ω
        ω冥魔腰帶ω
        ω冥魔腰帶ω
        ω冥魔腰帶ω
        ω冥魔腰帶ω
        ω冥魔腰帶ω

LONG);
	setup();
	replace_program(ROOM);
}
