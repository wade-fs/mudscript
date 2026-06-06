inherit ROOM;
void create() {
	set( "short", "魔劍室2" );
	set( "owner", "mekyn" );
	set( "object", ([
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount9"  : 1,
		"file4"    : "/open/gsword/obj1/blosword",
		"file9"    : "/open/gsword/obj1/blosword",
		"amount3"  : 150,
		"amount4"  : 1,
		"amount7"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 1,
		"file8"    : "/open/gsword/obj1/blosword",
		"amount6"  : 900,
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file10"   : "/open/gsword/obj1/blosword",
		"amount1"  : 300,
		"amount5"  : 1,
		"file7"    : "/open/gsword/obj1/blosword",
		"amount10" : 1,
		"amount2"  : 1,
		"file2"    : "/open/gsword/obj1/blosword",
	]) );
	set( "build", 10048 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room463.c",
		"east"      : "/open/clan/ou-cloud-club/room/room461",
	]) );
	set( "long", @LONG


╭╯   ╠═══╮   ║  ═╦═══╯╰╮  ╭╯╭╯╭╯║║  ╠╦═╦═╮
╰╭╯ ╯═╭═╯ ═╬═  ╰═╮═╮╭╬╯╭════╮╠╬═║║  ║  ║
╭╯   ╭═╯═╮ ╭╬╮╭═╮║║║╯║  ╰═╯╰═╯╯║  ╯║  ║  ║
╰═╯ ║╰═╮║ ║║║║  ║║╭╯╭╬╯║╯║╯║  ═╬═  ║  ║  ║
║║║ ╯      ╰ ║║║╰═╯╠╯╰╯║  ║╯║╯╰╮  ║    ║  ║  ║
╯╰╰   ╰═╮   ╯║╰═══╩═╯  ╯  ╩╯╩╯  ╰  ╯    ╯  ╯  ╯


LONG);
	setup();
	replace_program(ROOM);
}
