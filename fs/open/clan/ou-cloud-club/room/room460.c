inherit ROOM;
void create() {
	set( "short", "魔劍室4" );
	set( "owner", "mekyn" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/open/gsword/obj1/blosword",
		"file2"    : "/open/gsword/obj1/blosword",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/gsword/obj1/blosword",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/gsword/obj1/blosword",
		"file8"    : "/open/gsword/obj1/blosword",
		"file6"    : "/open/gsword/obj1/blosword",
		"amount9"  : 1,
		"file3"    : "/open/gsword/obj1/blosword",
		"file1"    : "/open/gsword/obj1/blosword",
		"file5"    : "/open/gsword/obj1/blosword",
	]) );
	set( "build", 10101 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room461.c",
		"east"      : "/open/clan/ou-cloud-club/room/room459",
	]) );
	set( "long", @LONG


  ║    ╭══╮  ╔═╮ ══╬══   ╮  ═╩╯╚═╯  ╰═════╗
═╬═╮║    ║  ║  ║ ╦═╩═╦ ╰╩╗║═╮══╗        ╭══╯
  ║  ║╠══╣  ╠═╮ ╯╭    ╰   ╭╯║  ║  ╔╯╰═══╬═══╮
  ║  ║║    ║  ║  ║ ═╯══╮ 　╰╗║  ║═╬═        ║
╭╯  ║╰══╯  ║═╯ ╰═╭═╯ ╔╦╯╯  ╯  ╯          ║
╯    ╰════╯╯     ══╯══   ╰══════╯    ╰═╝


LONG);
	setup();
	replace_program(ROOM);
}
