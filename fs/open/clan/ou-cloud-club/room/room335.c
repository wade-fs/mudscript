inherit ROOM;
void create() {
	set( "short", "ω冥魔指戒ω" );
	set( "owner", "enter" );
	set( "build", 10075 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room336",
		"west"      : "/open/clan/ou-cloud-club/room/room334.c",
	]) );
	set( "long", @LONG

        ω冥魔指戒ω
        ω冥魔指戒ω
        ω冥魔指戒ω
        ω冥魔指戒ω
        ω冥魔指戒ω
        ω冥魔指戒ω
        ω冥魔指戒ω
        ω冥魔指戒ω
        ω冥魔指戒ω
        ω冥魔指戒ω

LONG);
	setup();
	replace_program(ROOM);
}
