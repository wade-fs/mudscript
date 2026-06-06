inherit ROOM;
void create() {
	set( "short", "小徑" );
	set( "owner", "evonne" );
	set( "object", ([
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 885,
		"file3"    : "/open/mon/obj/mon-pill",
		"amount1"  : 81,
		"file8"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount2"  : 14,
		"amount8"  : 19,
		"amount6"  : 33,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/killer/obj/atman_pill",
		"amount5"  : 92,
		"amount3"  : 26,
	]) );
	set( "build", 11949 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room491.c",
		"south"     : "/open/clan/13_luck/room/room493",
	]) );
	set( "long", @LONG

　　這是條相當美麗的小路，一條清澈的小溪流流過，四周開著奇異
的花與草。就連樹木也都是你不曾見過的品種，往前遠遠的看過去是
一整片的森林，不過始終無法看的很清楚，除了奇異的花草，還有著
許多不知名的昆蟲四處飛舞著。 

LONG);
	setup();
	replace_program(ROOM);
}
