inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIY$Ｉ$HIC$１$NOR$" );
	set( "object", ([
		"file1"    : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount9"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount4"  : 1,
		"file3"    : "/open/center/obj/mechoufen-head",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount7"  : 1,
		"file9"    : "/open/center/obj/mechoufen-head",
		"amount6"  : 1,
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount1"  : 1,
		"file8"    : "/open/center/obj/mechoufen-head",
		"file10"   : "/open/center/obj/mechoufen-head",
		"file4"    : "/open/center/obj/mechoufen-head",
	]) );
	set( "build", 17879 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room715",
		"west"      : "/open/clan/ou-cloud-club/room/room712.c",
		"south"     : "/open/clan/ou-cloud-club/room/room703",
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
