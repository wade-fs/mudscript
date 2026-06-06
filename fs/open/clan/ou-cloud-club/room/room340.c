inherit ROOM;
void create() {
	set( "short", "ω冥魔寶墜ω" );
	set( "object", ([
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10582 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room345",
		"west"      : "/open/clan/ou-cloud-club/room/room339",
	]) );
	set( "long", @LONG

        ω冥魔寶墜ω
        ω冥魔寶墜ω
        ω冥魔寶墜ω
        ω冥魔寶墜ω
        ω冥魔寶墜ω
        ω冥魔寶墜ω
        ω冥魔寶墜ω
        ω冥魔寶墜ω
        ω冥魔寶墜ω
        ω冥魔寶墜ω

LONG);
	setup();
	replace_program(ROOM);
}
