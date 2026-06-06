inherit ROOM;
void create() {
	set( "short", "五色龍宮" );
	set( "object", ([
		"amount1"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount2"  : 1,
		"file8"    : "/open/mogi/castle/obj/seven2-dark-head",
		"file6"    : "/open/mogi/castle/obj/seven4-dark-head",
		"amount4"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file3"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file2"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount5"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount3"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount7"  : 1,
	]) );
	set( "owner", "kitty" );
	set( "build", 12942 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room53.c",
		"south"     : "/open/clan/free-zone/room/room54.c",
		"west"      : "/open/clan/free-zone/room/room56.c",
		"north"     : "/open/clan/free-zone/room/room55.c",
		"up"        : "/open/clan/free-zone/room/room57.c",
		"down"      : "/open/clan/free-zone/room/room58",
		"out"       : "/open/clan/free-zone/room/room37",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├五┤☆☆├色┤☆☆├龍┤☆☆├宮┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★


LONG);
	setup();
	replace_program(ROOM);
}
