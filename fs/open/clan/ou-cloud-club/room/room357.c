inherit ROOM;
void create() {
	set( "short", "$HIM$≡冥魔寶墜≡$NOR$" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount1"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 32381 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room367.c",
		"west"      : "/open/clan/ou-cloud-club/room/room358.c",
		"up"        : "/open/clan/ou-cloud-club/room/room377",
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
