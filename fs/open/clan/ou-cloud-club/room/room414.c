inherit ROOM;
void create() {
	set( "short", "阿華田之家" );
	set( "owner", "ovaltine" );
	set( "object", ([
		"file9"    : "/obj/gift/bingtang",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file2"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"file3"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"amount9"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"file6"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/unknowdan",
		"amount8"  : 1,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room159",
		"east"      : "/open/clan/ou-cloud-club/room/room164",
		"north"     : "/open/clan/ou-cloud-club/room/room401.c",
	]) );
	set( "build", 10354 );
	set( "light_up", 1 );
	set( "long", @LONG
  阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田
阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田
阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田
阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田
阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田
阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田阿華田

LONG);
	setup();
	replace_program(ROOM);
}
