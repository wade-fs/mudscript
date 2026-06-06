inherit ROOM;
void create() {
	set( "short", "$HIG$≡冥魔足環≡$NOR$" );
	set( "build", 10935 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room361.c",
		"up"        : "/open/clan/ou-cloud-club/room/room371",
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
