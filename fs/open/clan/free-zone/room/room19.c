inherit ROOM;
void create() {
	set( "short", "地下寶庫入口" );
	set( "object", ([
		"file3"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount1"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount7"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount5"  : 1,
		"amount10" : 1,
		"file7"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount6"  : 1,
		"file9"    : "/open/mogi/castle/obj/white-ghost-head",
		"amount4"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file8"    : "/open/mogi/castle/obj/black-ghost-head",
		"amount8"  : 1,
		"file2"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount3"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven3-dark-head",
	]) );
	set( "build", 12885 );
	set( "exits", ([
		"enter"     : "/open/clan/free-zone/room/room20",
		"up"        : "/open/clan/free-zone/room/hall",
	]) );
	set( "long", @LONG


☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★┌┬┐★
☆~├地┤☆├下┤☆├寶┤☆├庫┤☆├入┤☆├口┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆★☆★☆


LONG);
	setup();
	replace_program(ROOM);
}
