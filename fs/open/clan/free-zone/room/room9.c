inherit ROOM;
void create() {
	set( "short", "聖境南一路" );
	set( "object", ([
		"amount4"  : 10,
		"amount1"  : 1,
		"file5"    : "/open/ghost-hole/obj/light-spirit",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file4"    : "/open/mon/obj/thousand-nectar",
		"amount9"  : 1,
		"file8"    : "/open/ping/obj/poison_pill",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file7"    : "/obj/gift/shenliwan",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/ping/obj/poison_pill",
		"file9"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"amount10" : 892,
		"amount8"  : 848,
		"amount3"  : 1,
	]) );
	set( "build", 13400 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room11",
		"north"     : "/open/clan/free-zone/room/hall.c",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├南┤☆├一┤☆├路┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 

LONG);
	setup();
	replace_program(ROOM);
}
