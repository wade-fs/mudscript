inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIY$Ｉ$HIC$４$NOR$" );
	set( "owner", "long" );
	set( "object", ([
		"file1"    : "/open/center/obj/mechoufen-head",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount10" : 1,
		"file3"    : "/open/center/obj/mechoufen-head",
		"file8"    : "/open/center/obj/mechoufen-head",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/center/obj/mechoufen-head",
		"amount6"  : 1,
		"file4"    : "/open/center/obj/mechoufen-head",
		"file7"    : "/open/center/obj/mechoufen-head",
		"file2"    : "/open/center/obj/mechoufen-head",
		"file10"   : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/center/obj/mechoufen-head",
	]) );
	set( "build", 23384 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room718",
		"east"      : "/open/clan/ou-cloud-club/room/room713.c",
		"south"     : "/open/clan/ou-cloud-club/room/room706.c",
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
