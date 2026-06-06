inherit ROOM;
void create() {
	set( "short", "魔劍室1" );
	set( "object", ([
		"amount3"  : 679,
		"amount2"  : 276,
		"amount5"  : 54,
		"file3"    : "/open/mon/obj/mon-pill",
		"file7"    : "/open/fire-hole/obj/k-pill",
		"file8"    : "/open/mogi/castle/obj/leave",
		"file4"    : "/open/fire-hole/obj/y-pill",
		"amount7"  : 43,
		"file10"   : "/open/magic-manor/obj/fon-sky-sword",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount10" : 1,
		"file9"    : "/open/killer/memory/static",
		"amount4"  : 145,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 1,
		"amount1"  : 243,
		"amount8"  : 1,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount6"  : 70,
	]) );
	set( "owner", "mekyn" );
	set( "build", 10118 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room464.c",
		"east"      : "/open/clan/ou-cloud-club/room/room462",
	]) );
	set( "long", @LONG


     ╰╮╭╭═╦╦═╮  ╭═╯═══╮
     ╭╬╯╰═╩╩═╯  ║  ╰╮    ║
     ╯║  ╠═╦══╮═╬══╩══╬═
     ╭╬╯╯═╬═╮║  ║   ╮     ║
     ╯║  ╰═╬═╯║  ║   ╰╮   ║
       ╯  ══╩═╣╯  ╯          ╯
     ╭═══╦═══╯╭═══╦═══╮╭══╮╠═══╮
             ║        ╠═══╬═══╣║    ║╯═╭═╯
     ════╬════║      ║      ║╰╦═╯╭═╯═╮
             ║        ╰═══╬═══╯║╠═╯╯═══╰
             ║          ═══╬═══  ║║    ║      ║
             ║        ════╩═══╯╩╩═╯╰═══╯


LONG);
	setup();
	replace_program(ROOM);
}
