inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣～$HIC$龍$HIW$元$WHT$藏$NOR$" );
	set( "object", ([
		"amount7"  : 2,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/fire-hole/obj/y-pill",
		"file7"    : "/open/mon/obj/mon-pill",
		"amount5"  : 38,
		"amount3"  : 191,
		"amount2"  : 98,
		"amount4"  : 185,
		"amount1"  : 448,
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 3,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file3"    : "/open/fire-hole/obj/k-pill",
		"file2"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 10805 );
	set( "owner", "left" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room569.c",
		"south"     : "/open/clan/ou-cloud-club/room/room568.c",
		"north"     : "/open/clan/ou-cloud-club/room/room571",
		"up"        : "/open/clan/ou-cloud-club/room/room185.c",
		"east"      : "/open/clan/ou-cloud-club/room/room570.c",
	]) );
	set( "long", @LONG

                               ╔╗ ╦╦          ╦╦                          
                               ╠╣ ║║          ║║                          
         ╭╦╦╦╮╭╦╦╮╭╦╬╣╦═╦╭╦╦╮╦═╦╭╦╦╮╭╦╦╮         
         ╠╣║╠╣╠╣╠╣╠╣╠╣╠- ║╠╣╚╝╠- ║╠╣╠╣╠╣╠╣         
         ╠╣║╠╣╠╬╩╯╠╣╠╣╠- ║╠╣    ╠- ║╠╣╠╣╠╬╩╯         
         ╠╣║╠╣╠╣╔╗╠╣╠╣╠- ║╠╣╔╗╠- ║╠╣╠╣╠╣╔╗         
         ╚╝╩╚╝╰╩╩╯╰╩╩╝╰╦╯╰╩╩╯╰╦╯╚╝╚╝╰╩╩╯         
                                     │            │                           

LONG);
	setup();
	replace_program(ROOM);
}
