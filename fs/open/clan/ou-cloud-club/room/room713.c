inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIY$Ｉ$HIC$３$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/center/obj/mechoufen-head",
		"file1"    : "/open/center/obj/mechoufen-head",
		"amount5"  : 1,
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount2"  : 1,
		"file3"    : "/open/center/obj/mechoufen-head",
		"amount10" : 1,
		"amount4"  : 1,
		"file9"    : "/open/center/obj/mechoufen-head",
		"file10"   : "/open/center/obj/mechoufen-head",
		"amount3"  : 1,
		"file4"    : "/open/center/obj/mechoufen-head",
		"file8"    : "/open/center/obj/mechoufen-head",
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount7"  : 1,
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount9"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 17385 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room717",
		"east"      : "/open/clan/ou-cloud-club/room/room712.c",
		"west"      : "/open/clan/ou-cloud-club/room/room714.c",
		"south"     : "/open/clan/ou-cloud-club/room/room705.c",
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
