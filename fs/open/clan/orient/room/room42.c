inherit ROOM;
void create() {
	set( "short", "$HIW$『$HIY$舞郡主室$HIW$』$NOR$" );
	set( "owner", "cdrom" );
	set( "object", ([
		"file2"    : "/obj/gift/lingzhi",
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount3"  : 1,
		"file8"    : "/obj/gift/lingzhi",
		"amount8"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
	]) );
	set( "build", 10041 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room65",
		"east"      : "/open/clan/orient/room/room38.c",
	]) );
	set( "long", @LONG

此地初建, 空無一物。此地初建, 空無一物。此地初建, 空無一物。
此地初建, 空無一物。此地初建, 空無一物。此地初建, 空無一物。
此地初建, 空無一物。此地初建, 空無一物。此地初建, 空無一物。
此地初建, 空無一物。此地初建, 空無一物。此地初建, 空無一物。

LONG);
	setup();
	replace_program(ROOM);
}
