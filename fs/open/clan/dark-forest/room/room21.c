inherit ROOM;
void create() {
	set( "short", "神木群S" );
	set( "object", ([
		"amount5"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount8"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount7"  : 1,
	]) );
	set( "build", 10003 );
	set( "exits", ([
		"north"     : "/open/clan/dark-forest/room/room19",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
