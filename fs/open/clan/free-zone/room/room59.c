inherit ROOM;
void create() {
	set( "short", "丹藥寶庫" );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/center/obj/mechoufen-head",
		"file4"    : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount10" : 1,
		"file7"    : "/open/center/obj/mechoufen-head",
		"file5"    : "/open/center/obj/mechoufen-head",
		"file8"    : "/open/center/obj/mechoufen-head",
		"file10"   : "/open/center/obj/mechoufen-head",
		"amount6"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/center/obj/mechoufen-head",
		"amount9"  : 1,
		"file3"    : "/open/center/obj/mechoufen-head",
		"amount4"  : 1,
		"file9"    : "/open/center/obj/mechoufen-head",
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "owner", "fighter" );
	set( "build", 14483 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room60.c",
		"south"     : "/open/clan/free-zone/room/room62",
		"north"     : "/open/clan/free-zone/room/room20.c",
		"west"      : "/open/clan/free-zone/room/room61.c",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├丹┤☆☆├藥┤☆☆├寶┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★

LONG);
	setup();
	replace_program(ROOM);
}
