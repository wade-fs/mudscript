inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣～$HIR$煉$HIW$丹房" );
	set( "owner", "left" );
	set( "object", ([
		"file10"   : "/open/mon/obj/thousand-nectar",
		"amount10" : 15,
		"file9"    : "/open/fire-hole/obj/y-pill",
		"amount8"  : 25,
		"file3"    : "/open/killer/obj/atman_pill",
		"amount4"  : 175,
		"amount5"  : 14,
		"file6"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount7"  : 49,
		"amount3"  : 873,
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount1"  : 45,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/ping/obj/poison_pill",
		"file2"    : "/open/mon/obj/thousand-nectar",
		"amount2"  : 29,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 9,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 9,
	]) );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room134.c",
		"south"     : "/open/clan/ou-cloud-club/room/room489.c",
		"down"      : "/open/clan/ou-cloud-club/room/room567",
		"north"     : "/open/clan/ou-cloud-club/room/room481.c",
		"up"        : "/open/clan/ou-cloud-club/room/room519",
		"east"      : "/open/clan/ou-cloud-club/room/room443.c",
	]) );
	set( "light_up", 1 );
	set( "build", 31037 );
	set( "long", @LONG

         ╔═══╔═╮  ═╬═══╬═    ╭              ╭╔╮═╬╮         
         ║╠╦╯╯  ╚  ╔╯╔╯╮╔╯  ╭╯    █      ╭╯  ║  ║║         
         ║╯╬╯╔═╗  ╰╭║╭╣╰╭  ║║  ███    ║║╔╯═╬╬         
         ║╚╯╝╰╭╯  ╔╯╠╯║╔╯  ║║    █      ║║║    ║║         
         ╰═══╚╯╝  ╰╚╰╦╝╰╚  ║║═╦╬╦═  ║║╰╗═╬╯         
         ══╦═╦══  ╰═╦╬╦═╯  ║║  ║║║    ║║╮║═╬╯         
         ╔═╬═╬═╮  ╭╭╯║╰╮╮  ╯║╭║║║╮  ╯║╠╯═╬╯         
         ╠═╯═╰═╣  ║║  ║  ║║    ║║║║║║    ║╠╮  ║╭╮       
         ╰═════╝  ╚╯╰╝  ╰╝  ╰╝╚╯╝╰╝  ╰╝╯╰═╩╯╯       

LONG);
	setup();
	replace_program(ROOM);
}
