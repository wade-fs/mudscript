inherit ROOM;
void create() {
	set( "short", "$HIY$≡冥魔腰帶≡$NOR$" );
	set( "object", ([
		"file4"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10088 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room368.c",
		"up"        : "/open/clan/ou-cloud-club/room/room374",
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
