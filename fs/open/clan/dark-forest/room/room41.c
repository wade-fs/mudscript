inherit ROOM;
void create() {
	set( "short", "冰淇淋三號" );
	set( "object", ([
		"file8"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount4"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount8"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount5"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10204 );
	set( "owner", "mika" );
	set( "exits", ([
		"east"      : "/open/clan/dark-forest/room/room42.c",
		"north"     : "/open/clan/dark-forest/room/room44",
		"south"     : "/open/clan/dark-forest/room/room35.c",
		"west"      : "/open/clan/dark-forest/room/room43.c",
	]) );
	set( "long", @LONG
冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號
冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號
冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號
冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號
冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號
冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號
冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號冰淇淋三號
LONG);
	setup();
	replace_program(ROOM);
}
