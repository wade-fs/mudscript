inherit ROOM;
void create() {
	set( "short", "十三吉祥正門" );
	set( "object", ([
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"amount5"  : 1,
	]) );
	set( "owner", "mwf" );
	set( "build", 10272 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room417",
		"south"     : "/open/clan/13_luck/room/room419",
	]) );
	set( "long", @LONG


       ███████████████████████████████
       █                                                          █
       █      ║          ═══         ║       ══   ╗  ╔   █
       █      ║                     ══╬══  ═╦═  ═╦═   █
       █  ══╬══       ══        ═╩═    ║║║  ═╬═   █
       █      ║                     ╔═══╗  ║║║══╬══ █
       █      ║        ═════   ╚═══╝  ║║║    ║     █
       █                                                          █
       ███████████████████████████████

           『無  問  正  邪  ，  任  憑  諸  君  活  著  來  。』
           『莫  論  是  非  ，  只  許  眾  魂  死  著  去  。』

LONG);
	setup();
	replace_program(ROOM);
}
