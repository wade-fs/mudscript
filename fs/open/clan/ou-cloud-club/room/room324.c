inherit ROOM;
void create() {
	set( "short", "理財小幫手" );
	set( "object", ([
		"file4"    : "/open/ping/questsfan/obj/diamond_armor",
		"amount2"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount10" : 1,
		"amount5"  : 1,
		"file1"    : "/open/ping/obj/neck0",
		"amount7"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_legging",
		"file8"    : "/open/ping/questsfan/obj/diamond_belt",
		"file7"    : "/open/ping/questsfan/obj/diamond_cloak",
		"file5"    : "/open/ping/questsfan/obj/diamond_skirt",
		"file9"    : "/open/gsword/obj1/bpball",
		"amount6"  : 1,
		"file6"    : "/open/ping/questsfan/obj/diamond_boots",
		"amount8"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room315",
	]) );
	set( "build", 12884 );
	set( "long", @LONG
  理財 賺錢 理財 賺錢 理財 賺錢 理財
理財 賺錢 理財 賺錢 理財 賺錢 理財 賺錢
賺錢 理財 賺錢 理財 賺錢 理財 賺錢 理財
理財 賺錢 理財 賺錢 理財 賺錢 理財 賺錢
賺錢 理財 賺錢 理財 賺錢 理財 賺錢 理財
理財 賺錢 理財 賺錢 理財 賺錢 理財 賺錢
賺錢 理財 賺錢 理財 賺錢 理財 賺錢 理財
LONG);
	setup();
	replace_program(ROOM);
}
