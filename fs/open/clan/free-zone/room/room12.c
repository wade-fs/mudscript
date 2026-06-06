inherit ROOM;
void create() {
	set( "short", "聖境北二街" );
	set( "object", ([
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10655 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room10.c",
		"north"     : "/open/clan/free-zone/room/room14",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├北┤☆├二┤☆├街┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 


LONG);
	setup();
	replace_program(ROOM);
}
