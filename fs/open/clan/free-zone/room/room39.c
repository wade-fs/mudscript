inherit ROOM;
void create() {
	set( "short", "聖境南大門" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 2,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/power",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/center/obj/mechoufen-head",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 27938 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room40",
		"enter"     : "/open/clan/free-zone/room/room15.c",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├南┤☆├大┤☆├門┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 


LONG);
	setup();
	replace_program(ROOM);
}
