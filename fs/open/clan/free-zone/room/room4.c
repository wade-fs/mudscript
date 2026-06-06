inherit ROOM;
void create() {
	set( "short", "聖境西一道" );
	set( "owner", "fighter" );
	set( "object", ([
		"amount5"  : 323,
		"amount2"  : 175,
		"amount10" : 1,
		"file7"    : "/open/gblade/obj/dragon_book",
		"amount6"  : 195,
		"file9"    : "/open/mon/obj/mon-pill",
		"amount8"  : 1087,
		"file1"    : "/open/fire-hole/obj/w-pill",
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/open/ghost-hole/obj/light-spirit",
		"amount9"  : 654,
		"amount7"  : 1,
		"amount1"  : 199,
		"file5"    : "/open/fire-hole/obj/y-pill",
		"file8"    : "/open/ping/obj/poison_pill",
		"amount3"  : 239,
		"amount4"  : 96,
	]) );
	set( "build", 27169 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/room7",
		"east"      : "/open/clan/free-zone/room/hall.c",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├西┤☆├一┤☆├道┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 

LONG);
	setup();
	replace_program(ROOM);
}
