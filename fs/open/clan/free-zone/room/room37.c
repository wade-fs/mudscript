inherit ROOM;
void create() {
	set( "short", "龍域" );
	set( "object", ([
		"amount10" : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/center/obj/mechoufen-head",
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount7"  : 1,
		"file9"    : "/open/center/obj/mechoufen-head",
		"file4"    : "/open/center/obj/mechoufen-head",
		"file3"    : "/open/center/obj/mechoufen-head",
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount4"  : 1,
		"file1"    : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount5"  : 1,
		"file10"   : "/open/center/obj/mechoufen-head",
		"amount8"  : 1,
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount2"  : 1,
	]) );
	set( "build", 10450 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room38.c",
		"enter"     : "/open/clan/free-zone/room/room52",
		"south"     : "/open/clan/free-zone/room/room20",
	]) );
	set( "long", @LONG

    ★☆★☆★☆☆☆★☆☆☆★☆★☆★
  ★☆★☆┌┬┐☆☆┬☆☆┌┬┐☆★☆★
☆☆☆★☆├龍┤☆☆★☆☆├域┤☆★☆☆☆
  ★☆★☆└┴┘☆☆┴☆☆└┴┘☆★☆★
    ★☆★☆★☆☆☆★☆☆☆★☆★☆★


LONG);
	setup();
	replace_program(ROOM);
}
