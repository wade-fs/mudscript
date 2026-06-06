inherit ROOM;
void create() {
	set( "short", "$HIY$熱$HIR$帶$HIC$雨$HIG$林$NOR$" );
	set( "object", ([
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 28317 );
	set( "exits", ([
		"down"      : "/open/clan/dark-forest/room/hall.c",
		"east"      : "/open/clan/dark-forest/room/room17",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
