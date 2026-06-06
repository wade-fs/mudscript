inherit ROOM;
void create() {
	set( "short", "ω冥魔肩甲ω" );
	set( "object", ([
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10025 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room342",
		"west"      : "/open/clan/ou-cloud-club/room/room344.c",
	]) );
	set( "long", @LONG

        ω冥魔肩甲ω
        ω冥魔肩甲ω
        ω冥魔肩甲ω
        ω冥魔肩甲ω
        ω冥魔肩甲ω
        ω冥魔肩甲ω
        ω冥魔肩甲ω
        ω冥魔肩甲ω
        ω冥魔肩甲ω
        ω冥魔肩甲ω

LONG);
	setup();
	replace_program(ROOM);
}
