inherit ROOM;
void create() {
	set( "short", "$HIY$菩提$HIC$學院$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/ping/obj/ra-head",
		"file6"    : "/open/ping/obj/ra-head",
		"file2"    : "/open/ping/obj/ra-head",
		"file3"    : "/open/ping/obj/ra-head",
		"file8"    : "/open/ping/obj/ra-head",
		"amount4"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/ping/obj/ra-head",
		"file9"    : "/open/ping/obj/ra-head",
		"amount8"  : 1,
		"file10"   : "/open/ping/obj/ra-head",
		"amount5"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/ping/obj/ra-head",
		"amount3"  : 1,
		"file7"    : "/open/ping/obj/ra-head",
		"amount7"  : 1,
	]) );
	set( "owner", "auo" );
	set( "build", 10388 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room256",
		"north"     : "/open/clan/time-limit/room/room200.c",
	]) );
	set( "long", @LONG
菩提學院是佛教徒修練的學院,菩提二字是來自於佛祖在菩提樹下得道,往後便常以菩提
代表佛教,學院內有數不盡的藏書可供參詳佛理,有助於修習,還有金剛堂作為修練武藝
的場所,金剛堂上有一幅達摩祖師的畫像,達摩祖師不但講授佛理,更指點修行者練武以
強筋健骨,為少林武學的根源

LONG);
	setup();
	replace_program(ROOM);
}
