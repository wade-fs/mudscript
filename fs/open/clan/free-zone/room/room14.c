inherit ROOM;
void create() {
	set( "short", "聖境北三街" );
	set( "object", ([
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/ghost-hole/obj/light-spirit",
		"amount2"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 10210 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room12.c",
		"north"     : "/open/clan/free-zone/room/room16",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├北┤☆├三┤☆├街┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 


LONG);
	setup();
	replace_program(ROOM);
}
