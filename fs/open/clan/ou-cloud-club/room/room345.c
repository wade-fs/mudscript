inherit ROOM;
void create() {
	set( "short", "ω冥魔甲冑ω" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
	]) );
	set( "owner", "enter" );
	set( "light_up", 1 );
	set( "build", 10030 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room344",
		"west"      : "/open/clan/ou-cloud-club/room/room340.c",
	]) );
	set( "long", @LONG

        ω冥魔甲冑ω
        ω冥魔甲冑ω
        ω冥魔甲冑ω
        ω冥魔甲冑ω
        ω冥魔甲冑ω
        ω冥魔甲冑ω
        ω冥魔甲冑ω
        ω冥魔甲冑ω
        ω冥魔甲冑ω
        ω冥魔甲冑ω

LONG);
	setup();
	replace_program(ROOM);
}
