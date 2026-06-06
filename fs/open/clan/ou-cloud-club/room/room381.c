inherit ROOM;
void create() {
	set( "short", "$HIY$≡冥魔肩甲Ⅱ≡$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armband",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount9"  : 1,
		"amount10" : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "build", 14119 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room368",
	]) );
	set( "long", @LONG
肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲

LONG);
	setup();
	replace_program(ROOM);
}
