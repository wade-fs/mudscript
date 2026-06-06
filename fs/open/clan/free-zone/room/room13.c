inherit ROOM;
void create() {
	set( "short", "聖境南三路" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10955 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room15",
		"north"     : "/open/clan/free-zone/room/room11.c",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├南┤☆├三┤☆├路┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 


LONG);
	setup();
	replace_program(ROOM);
}
