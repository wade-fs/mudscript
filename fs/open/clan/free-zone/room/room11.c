inherit ROOM;
void create() {
	set( "short", "聖境南二路" );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/open/fire-hole/obj/b-pill",
		"amount4"  : 5,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/fire-hole/obj/k-pill",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount5"  : 5,
	]) );
	set( "build", 10090 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room13",
		"north"     : "/open/clan/free-zone/room/room9.c",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├南┤☆├二┤☆├路┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 

LONG);
	setup();
	replace_program(ROOM);
}
