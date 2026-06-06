inherit ROOM;
void create() {
	set( "short", "$HIR$≡冥魔脛甲Ⅱ≡$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount2"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount9"  : 1,
		"amount10" : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
	]) );
	set( "build", 10274 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room362",
	]) );
	set( "long", @LONG
脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲
冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲
冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲
冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲
冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲
冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲冥魔脛甲

LONG);
	setup();
	replace_program(ROOM);
}
