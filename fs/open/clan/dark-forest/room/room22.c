inherit ROOM;
void create() {
	set( "short", "百年神木" );
	set( "object", ([
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount10" : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount8"  : 1,
	]) );
	set( "build", 10003 );
	set( "exits", ([
		"south"     : "/open/clan/dark-forest/room/room19.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
