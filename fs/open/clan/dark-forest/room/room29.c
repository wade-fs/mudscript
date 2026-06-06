inherit ROOM;
void create() {
	set( "short", "硬的保險櫃" );
	set( "owner", "robo" );
	set( "object", ([
		"amount7"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10044 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/dark-forest/room/room28",
		"west"      : "/open/clan/dark-forest/room/room32",
		"south"     : "/open/clan/dark-forest/room/room33",
		"north"     : "/open/clan/dark-forest/room/room31.c",
		"east"      : "/open/clan/dark-forest/room/room30.c",
	]) );
	set( "long", @LONG
此此此此此　　地地地地地　　無無無無無　銀銀銀銀銀
　　此此此此此　　地地地地地　　無無無無無　銀銀銀銀銀
　　此此此此此　　地地地地地　　無無無無無　銀銀銀銀銀
　　此此此此此　　地地地地地　　無無無無無　銀銀銀銀銀
　　此此此此此　　地地地地地　　無無無無無　銀銀銀銀銀
LONG);
	setup();
	replace_program(ROOM);
}
