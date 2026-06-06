inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIY$Ⅱ$HIC$４$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount4"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
	]) );
	set( "build", 10052 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room709",
		"north"     : "/open/clan/ou-cloud-club/room/room706",
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
