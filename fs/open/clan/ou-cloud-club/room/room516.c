inherit ROOM;
void create() {
	set( "short", "3F4Ws" );
	set( "owner", "success" );
	set( "object", ([
		"amount3"  : 35,
		"file7"    : "/open/ping/obj/poison_pill",
		"file6"    : "/obj/stone/suipian",
		"amount1"  : 1,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 210,
		"file2"    : "/obj/stone/powder",
		"amount7"  : 7,
		"file1"    : "/open/port/obj/wolf_ring",
		"amount6"  : 5,
		"amount5"  : 1,
		"amount4"  : 5,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/obj/stone/jiao",
	]) );
	set( "build", 12060 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room416",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
