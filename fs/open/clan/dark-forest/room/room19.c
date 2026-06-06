inherit ROOM;
void create() {
	set( "short", "神木群" );
	set( "object", ([
		"amount10" : 1,
		"file10"   : "/obj/gift/bingtang",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount6"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount5"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount7"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10203 );
	set( "exits", ([
		"down"      : "/open/clan/dark-forest/room/room2.c",
		"up"        : "/open/clan/dark-forest/room/room20.c",
		"out"       : "/open/clan/dark-forest/room/room18.c",
		"north"     : "/open/clan/dark-forest/room/room22",
		"south"     : "/open/clan/dark-forest/room/room21.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
