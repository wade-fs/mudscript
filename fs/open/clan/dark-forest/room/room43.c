inherit ROOM;
void create() {
	set( "short", "提升能力丹藥房" );
	set( "object", ([
		"file7"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"amount5"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file8"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file3"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10289 );
	set( "owner", "mika" );
	set( "exits", ([
		"east"      : "/open/clan/dark-forest/room/room41",
	]) );
	set( "long", @LONG
三號左邊三號左邊三號左邊三號左邊三號左邊
三號左邊三號左邊三號左邊三號左邊三號左邊
三號左邊三號左邊三號左邊三號左邊三號左邊
三號左邊三號左邊三號左邊三號左邊三號左邊
三號左邊三號左邊三號左邊三號左邊三號左邊
三號左邊三號左邊三號左邊三號左邊三號左邊
三號左邊三號左邊三號左邊三號左邊三號左邊
LONG);
	setup();
	replace_program(ROOM);
}
