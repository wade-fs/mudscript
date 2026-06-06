inherit ROOM;
void create() {
	set( "short", "聖境西二道" );
	set( "owner", "dragon" );
	set( "object", ([
		"file10"   : "/open/magic-manor/obj/lunar-heart",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount2"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file8"    : "/open/ghost-hole/obj/light-spirit",
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount8"  : 1,
		"file3"    : "/daemon/class/blademan/obj/mar-blade",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 14696 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/room8",
		"east"      : "/open/clan/free-zone/room/room4",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├西┤☆├二┤☆├道┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 

LONG);
	setup();
	replace_program(ROOM);
}
