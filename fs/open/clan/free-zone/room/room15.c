inherit ROOM;
void create() {
	set( "short", "聖境南四路" );
	set( "object", ([
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file8"    : "/obj/gift/hobowdan",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/obj/hwa-je-icer",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 11328 );
	set( "exits", ([
		"out"       : "/open/clan/free-zone/room/room39",
		"north"     : "/open/clan/free-zone/room/room13.c",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├南┤☆├四┤☆├路┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 


LONG);
	setup();
	replace_program(ROOM);
}
