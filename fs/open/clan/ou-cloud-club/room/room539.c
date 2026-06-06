inherit ROOM;
void create() {
	set( "short", "一望無際" );
	set( "owner", "core" );
	set( "light_up", 1 );
	set( "object", ([
		"amount6"  : 18,
		"amount1"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 42,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/daemon/class/blademan/obj/iceblade",
		"file5"    : "/open/fire-hole/obj/w-pill",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file6"    : "/open/mon/obj/mon-pill",
		"file7"    : "/open/fire-hole/obj/k-pill",
		"amount5"  : 61,
		"amount7"  : 4,
	]) );
	set( "build", 10206 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room536",
		"south"     : "/open/clan/ou-cloud-club/room/room589",
	]) );
	set( "long", @LONG

草草草草草草草草草草草草草草草草草草草草草草草草草草草草
草草草草草草草草草草草草草草草草草草草草草草草草草草草草
地地地地地地地地地地地地地地地地地地地地地地地地地地地地
地地地地地地地地地地地地地地地地地地地地地地地地地地地地
LONG);
	setup();
	replace_program(ROOM);
}
