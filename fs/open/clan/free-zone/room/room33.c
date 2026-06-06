inherit ROOM;
void create() {
	set( "short", "八傑聚靈地" );
	set( "owner", "dragon" );
	set( "object", ([
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10486 );
	set( "exits", ([
		"down"      : "/open/clan/free-zone/room/room28",
		"west"      : "/open/clan/free-zone/room/room29.c",
		"south"     : "/open/clan/free-zone/room/room35.c",
		"up"        : "/open/clan/free-zone/room/room34.c",
		"north"     : "/open/clan/free-zone/room/room31.c",
		"out"       : "/open/clan/free-zone/room/room22",
		"east"      : "/open/clan/free-zone/room/room32.c",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├八┤☆├傑┤☆├聚┤☆├靈┤☆├地┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 


LONG);
	setup();
	replace_program(ROOM);
}
