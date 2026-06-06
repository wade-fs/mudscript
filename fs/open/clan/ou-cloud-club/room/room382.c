inherit ROOM;
void create() {
	set( "short", "$HIR$≡冥魔披風Ⅱ≡$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount7"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount10" : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount6"  : 1,
	]) );
	set( "build", 13797 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room359",
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
