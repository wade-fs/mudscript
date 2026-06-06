inherit ROOM;
void create() {
	set( "short", "$HIR$≡冥魔披風≡$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount9"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-cloak",
	]) );
	set( "build", 10470 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room369.c",
		"up"        : "/open/clan/ou-cloud-club/room/room382",
		"north"     : "/open/clan/ou-cloud-club/room/room362.c",
	]) );
	set( "long", @LONG
披風冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風
冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風
冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風
冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風
冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風
冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風冥魔披風
LONG);
	setup();
	replace_program(ROOM);
}
