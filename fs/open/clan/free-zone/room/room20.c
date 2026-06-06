inherit ROOM;
void create() {
	set( "short", "地下寶庫" );
	set( "object", ([
		"file3"    : "/open/center/obj/mechoufen-head",
		"amount1"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount7"  : 1,
		"file1"    : "/open/center/obj/mechoufen-head",
		"amount5"  : 1,
		"amount10" : 1,
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount6"  : 1,
		"file9"    : "/open/center/obj/mechoufen-head",
		"amount4"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/center/obj/mechoufen-head",
		"file4"    : "/open/center/obj/mechoufen-head",
		"file8"    : "/open/center/obj/mechoufen-head",
		"amount8"  : 1,
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount3"  : 1,
		"file5"    : "/open/center/obj/mechoufen-head",
	]) );
	set( "build", 11390 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room21.c",
		"south"     : "/open/clan/free-zone/room/room59",
		"north"     : "/open/clan/free-zone/room/room37.c",
		"west"      : "/open/clan/free-zone/room/room22.c",
		"out"       : "/open/clan/free-zone/room/room19.c",
	]) );
	set( "long", @LONG

  ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├地┤☆☆├下┤☆☆├寶┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
  ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★


LONG);
	setup();
	replace_program(ROOM);
}
