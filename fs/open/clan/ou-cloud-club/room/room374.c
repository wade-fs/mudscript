inherit ROOM;
void create() {
	set( "short", "$HIY$≡冥魔腰帶Ⅱ≡$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount1"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount4"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount10" : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount6"  : 1,
	]) );
	set( "build", 10165 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room364",
	]) );
	set( "long", @LONG
腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶
冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶
冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶
冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶
冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶
冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶冥魔腰帶

LONG);
	setup();
	replace_program(ROOM);
}
