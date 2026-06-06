inherit ROOM;
void create() {
	set( "short", "錦華閣" );
	set( "owner", "roar" );
	set( "object", ([
		"amount8"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount9"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
	]) );
	set( "build", 10056 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room397",
	]) );
	set( "long", @LONG

    你踏進拳堂的後廳，一陣香氣向你直撲而來，原來這裡是拳十三休息
的地方，通常這裡是不允許任何人進入的，眼見兩旁侍女正在打掃這裡，
你不禁好奇的抬頭一望，看到一塊橫匾，上面寫著三個大字『錦華閣』。

LONG);
	setup();
	replace_program(ROOM);
}
