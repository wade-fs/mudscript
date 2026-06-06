inherit ROOM;
void create() {
	set( "short", "原野" );
	set( "object", ([
		"file1"    : "/open/mon/obj/mon-pill",
		"amount4"  : 1,
		"file8"    : "/open/ghost-hole/obj/wind-spirit",
		"file6"    : "/open/ping/questsfan/obj/diamond_boots",
		"amount9"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount10" : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/ping/questsfan/obj/diamond_cloak",
		"file5"    : "/open/ping/questsfan/obj/diamond_legging",
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"amount2"  : 161,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 626,
		"file7"    : "/open/killer/obj/atman_pill",
		"file10"   : "/open/ping/questsfan/obj/diamond_armor",
		"amount7"  : 940,
		"amount8"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10829 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room555",
	]) );
	set( "long", @LONG
以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,
以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,
以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,
以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,
以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,以後再來寫,
LONG);
	setup();
	replace_program(ROOM);
}
