inherit ROOM;
void create() {
	set( "short", "魔劍室3" );
	set( "owner", "mekyn" );
	set( "object", ([
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 400,
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 900,
		"file9"    : "/open/gsword/obj/dragon-sword",
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount5"  : 400,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10074 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room462.c",
		"east"      : "/open/clan/ou-cloud-club/room/room460",
	]) );
	set( "long", @LONG


 ╰═╬═══╬═╯  ╭╯    ═══╮╭═══════╮╭═══╩════
   ╭═╦═╦═╮  ╭╯  ╭        ║║════╬●═║║ ═╬═══╬═
 ╭╩╦╩═╩═╩╮╰╮╭╯        ║║╭══╮║    ║║   ╰═══╯
 ║╭╯╦═══╮║  ╭╯          ║║╰══╯╰╮╯║║ ╰═════╮
       ╰╮╭═╯  ╭╯  ╰╮  ╮  ║║═══╯═╰═║║   ╰═╭══╯
       ╭═╯      ╰═══╣  ╰═╯╰═══════╯╯ ═══╯╰══


LONG);
	setup();
	replace_program(ROOM);
}
