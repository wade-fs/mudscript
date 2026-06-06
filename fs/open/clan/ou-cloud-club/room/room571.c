inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣～$BLK$密$HIW$室" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount5"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven2-dark-head",
		"file5"    : "/open/killer/obj/kill_yar_head",
		"amount2"  : 1,
		"file2"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount4"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven4-dark-head",
		"amount6"  : 1,
		"file3"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount7"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven1-dark-head",
	]) );
	set( "build", 10352 );
	set( "owner", "left" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room567",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
