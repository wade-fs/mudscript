inherit ROOM;
void create() {
	set( "short", "$HIY$≡冥魔肩甲≡$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount4"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount5"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount10" : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount6"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armband",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount9"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount7"  : 1,
	]) );
	set( "build", 11555 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room365.c",
		"west"      : "/open/clan/ou-cloud-club/room/room364.c",
		"up"        : "/open/clan/ou-cloud-club/room/room381",
	]) );
	set( "long", @LONG
肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲冥魔肩甲
LONG);
	setup();
	replace_program(ROOM);
}
