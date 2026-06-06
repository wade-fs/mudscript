inherit ROOM;
void create() {
	set( "short", "$HIG$≡冥魔指戒≡$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount6"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-ring",
	]) );
	set( "light_up", 1 );
	set( "build", 10322 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room358.c",
		"up"        : "/open/clan/ou-cloud-club/room/room373",
		"north"     : "/open/clan/ou-cloud-club/room/room361.c",
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
