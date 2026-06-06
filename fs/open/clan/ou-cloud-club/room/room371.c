inherit ROOM;
void create() {
	set( "short", "$HIG$≡冥魔足環Ⅱ≡$NOR$ " );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-pants",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount9"  : 1,
		"amount10" : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
	]) );
	set( "light_up", 1 );
	set( "build", 10153 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room360",
	]) );
	set( "long", @LONG
足環冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環
冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環
冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環
冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環
冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環
冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環冥魔足環

LONG);
	setup();
	replace_program(ROOM);
}
