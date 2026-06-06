inherit ROOM;
void create() {
	set( "short", "ω冥魔邪盾ω" );
	set( "object", ([
		"amount8"  : 1,
		"amount4"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"amount1"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"file4"    : "/obj/gift/unknowdan",
	]) );
	set( "owner", "enter" );
	set( "build", 10183 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room335",
		"west"      : "/open/clan/ou-cloud-club/room/room333.c",
	]) );
	set( "long", @LONG

        ω冥魔邪盾ω
        ω冥魔邪盾ω
        ω冥魔邪盾ω
        ω冥魔邪盾ω
        ω冥魔邪盾ω
        ω冥魔邪盾ω
        ω冥魔邪盾ω
        ω冥魔邪盾ω
        ω冥魔邪盾ω
        ω冥魔邪盾ω

LONG);
	setup();
	replace_program(ROOM);
}
