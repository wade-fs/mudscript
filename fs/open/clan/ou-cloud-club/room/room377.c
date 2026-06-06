inherit ROOM;
void create() {
	set( "short", "$HIM$≡冥魔寶墜Ⅱ≡$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount7"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount5"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 11159 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room357",
	]) );
	set( "long", @LONG
寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜
冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜
冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜
冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜
冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜
冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜
冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜冥魔寶墜


LONG);
	setup();
	replace_program(ROOM);
}
