inherit ROOM;
void create() {
	set( "short", "雷峰試煉塔一樓" );
	set( "object", ([
		"file8"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount5"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount7"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount8"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 30318 );
	set( "exits", ([
		"up"        : "/open/clan/free-zone/room/room46",
		"out"       : "/open/clan/free-zone/room/room43",
		"north"     : "/open/clan/free-zone/room/room45.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
