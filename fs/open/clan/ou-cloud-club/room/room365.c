inherit ROOM;
void create() {
	set( "short", "$HIY$≡冥魔甲冑≡$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armor",
	]) );
	set( "build", 10894 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room358.c",
		"west"      : "/open/clan/ou-cloud-club/room/room368.c",
		"up"        : "/open/clan/ou-cloud-club/room/room375",
	]) );
	set( "long", @LONG
甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
LONG);
	setup();
	replace_program(ROOM);
}
