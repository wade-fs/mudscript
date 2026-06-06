inherit ROOM;
void create() {
	set( "short", "cowboy的家" );
	set( "owner", "cowboy" );
	set( "build", 10493 );
	set( "light_up", 1 );
	set( "object", ([
		"file6"    : "/obj/gift/unknowdan",
		"amount4"  : 141,
		"amount6"  : 1,
		"amount5"  : 26,
		"amount2"  : 232,
		"file1"    : "/open/killer/obj/k_ring",
		"amount9"  : 26,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 31,
		"amount3"  : 221,
		"amount1"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"file4"    : "/open/mon/obj/mon-pill",
		"amount10" : 1,
		"file9"    : "/open/fire-hole/obj/k-pill",
		"file5"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 1,
		"file10"   : "/open/capital/obj/4-3",
	]) );
	set( "exits", ([
		"lin"       : "/open/clan/ou-cloud-club/room/room703",
		"east"      : "/open/clan/ou-cloud-club/room/room18.c",
		"enter"     : "/open/clan/ou-cloud-club/room/room697.c",
	]) );
	set( "long", @LONG

$HIB$灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌灌灌灌$HIC$水$HIB$灌灌灌灌灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌灌灌灌$HIC$水水$HIB$灌灌灌灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌灌灌灌$HIC$水水$HIB$灌灌灌灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌灌灌灌$HIC$水水$HIB$灌灌灌灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌灌灌灌$HIC$水水$HIB$灌灌灌灌灌$HIC$水水$HIB$灌灌灌灌灌
灌灌灌灌灌灌灌灌灌$HIC$水水水$HIB$灌灌灌灌$HIC$水水水$HIB$灌灌灌灌灌
灌灌$HIC$水水水水水水水水水水$HIB$灌灌$HIC$水水水$HIB$灌灌灌灌灌灌灌
灌灌$HIC$水水水水水水水水水水水水水$HIB$灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌灌$HIC$水水水水水水$HIB$灌灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌$HIC$水水水水水水水$HIB$灌灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌$HIC$水水$HIB$灌$HIC$水水$HIB$灌$HIC$水水$HIB$灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌$HIC$水水$HIB$灌灌$HIC$水水$HIB$灌灌$HIC$水水$HIB$灌灌灌灌灌灌灌灌
灌灌灌灌灌灌$HIC$水水$HIB$灌灌$HIC$水水$HIB$灌灌灌$HIC$水水$HIB$灌灌灌灌灌灌灌
灌灌灌灌灌$HIC$水水$HIB$灌灌灌$HIC$水水$HIB$灌灌灌$HIC$水水水$HIB$灌灌灌灌灌灌
灌灌灌灌灌$HIC$水水$HIB$灌灌灌$HIC$水水$HIB$灌灌灌灌$HIC$水水水水$HIB$灌灌灌灌
灌灌灌灌$HIC$水水$HIB$灌灌灌灌$HIC$水水$HIB$灌灌灌灌$HIC$水水水水水$HIB$灌灌灌
灌灌灌$HIC$水水$HIB$灌灌灌灌灌$HIC$水水$HIB$灌灌灌灌灌$HIC$水水水水水$HIB$灌灌
灌灌$HIC$水水$HIB$灌灌灌灌灌灌$HIC$水水$HIB$灌灌灌灌灌灌$HIC$水水$HIB$灌灌灌灌
灌灌灌灌灌灌灌灌$HIC$水水水水$HIB$灌灌灌灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌灌灌$HIC$水水水$HIB$灌灌灌灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌灌灌灌$HIC$水$HIB$灌灌灌灌灌灌灌灌灌灌灌灌灌
灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌灌$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
