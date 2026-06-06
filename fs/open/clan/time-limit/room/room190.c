inherit ROOM;
void create() {
	set( "short", "牡羊宮" );
	set( "object", ([
		"file5"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"amount1"  : 33,
		"file1"    : "/obj/stone/powder",
		"amount2"  : 36,
		"file2"    : "/obj/stone/jiao",
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file4"    : "/obj/stone/suipian",
		"file7"    : "/open/mogi/dragon/obj/dragon-head",
		"amount4"  : 1,
	]) );
	set( "owner", "jar" );
	set( "build", 10031 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room19",
		"west"      : "/open/clan/time-limit/room/room191.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
