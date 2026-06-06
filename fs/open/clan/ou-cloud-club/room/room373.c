inherit ROOM;
void create() {
	set( "short", "$HIG$≡冥魔指戒Ⅱ≡$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-ring",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount2"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount9"  : 1,
		"amount10" : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-ring",
	]) );
	set( "light_up", 1 );
	set( "build", 17598 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room363",
	]) );
	set( "long", @LONG
指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒
冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒
冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒
冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒
冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒
冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒冥魔指戒

LONG);
	setup();
	replace_program(ROOM);
}
