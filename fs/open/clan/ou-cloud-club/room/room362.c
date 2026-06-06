inherit ROOM;
void create() {
	set( "short", "$HIR$≡冥魔脛甲≡$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount4"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
	]) );
	set( "build", 11897 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room359",
		"up"        : "/open/clan/ou-cloud-club/room/room370",
		"north"     : "/open/clan/ou-cloud-club/room/room358.c",
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
