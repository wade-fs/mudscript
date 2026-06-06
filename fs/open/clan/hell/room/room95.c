inherit ROOM;
void create() {
	set( "short", "這是巫師交誼的地方 - /open/wiz/hall1" );
	set( "owner", "vatsu" );
	set( "object", ([
		"file5"    : "/open/killer/obj/dagger",
		"amount9"  : 1,
		"file1"    : "/daemon/class/fighter/ywgem",
		"file8"    : "/daemon/class/fighter/armband",
		"amount3"  : 1,
		"file3"    : "/open/killer/weapon/k_boot3",
		"amount5"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/killer/obj/k_ring",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/killer/obj/dagger",
		"amount10" : 1,
		"file9"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/killer/weapon/k_cloth3",
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 11226 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room2.c",
		"south"     : "/open/clan/hell/room/room128",
		"west"      : "/open/clan/hell/room/room133.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
