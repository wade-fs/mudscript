inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIY$Ｙ$HIC$２$NOR$" );
	set( "owner", "mekyn" );
	set( "object", ([
		"amount10" : 1,
		"amount2"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount1"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven1-dark-head",
		"file9"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount9"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven5-dark-head",
		"file3"    : "/open/mogi/castle/obj/seven2-dark-head",
		"file5"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file10"   : "/open/mogi/dragon/obj/dragon-head",
		"file7"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount6"  : 1,
		"file2"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file8"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount8"  : 1,
	]) );
	set( "build", 10495 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room715",
		"down"      : "/open/clan/ou-cloud-club/room/room712",
		"west"      : "/open/clan/ou-cloud-club/room/room717.c",
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
