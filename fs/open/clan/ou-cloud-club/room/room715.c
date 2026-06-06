inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIY$Ｙ$HIC$１$NOR$" );
	set( "owner", "mekyn" );
	set( "object", ([
		"file9"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file1"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount5"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file4"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount9"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file3"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file8"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file6"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10125 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room711",
		"west"      : "/open/clan/ou-cloud-club/room/room716",
	]) );
	set( "light_up", 1 );
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
