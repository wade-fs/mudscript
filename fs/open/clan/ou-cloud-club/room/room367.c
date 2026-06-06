inherit ROOM;
void create() {
	set( "short", "$HIM$≡冥魔邪盾≡$NOR$" );
	set( "build", 10480 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room366.c",
		"west"      : "/open/clan/ou-cloud-club/room/room357.c",
		"up"        : "/open/clan/ou-cloud-club/room/room376",
	]) );
	set( "long", @LONG
邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
LONG);
	setup();
	replace_program(ROOM);
}
