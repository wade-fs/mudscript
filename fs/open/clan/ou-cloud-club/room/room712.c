inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIY$Ｉ$HIC$２$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file10"   : "/open/mogi/castle/obj/seven5-dark-head",
		"amount8"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount5"  : 1,
		"file8"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file3"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount4"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount6"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven2-dark-head",
		"file6"    : "/open/mogi/castle/obj/seven4-dark-head",
		"amount1"  : 1,
		"file9"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount9"  : 1,
		"amount10" : 1,
		"file2"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount2"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven1-dark-head",
	]) );
	set( "build", 17030 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room716",
		"east"      : "/open/clan/ou-cloud-club/room/room711.c",
		"west"      : "/open/clan/ou-cloud-club/room/room713.c",
		"south"     : "/open/clan/ou-cloud-club/room/room704",
	]) );
	set( "long", @LONG

此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。

LONG);
	setup();
	replace_program(ROOM);
}
