inherit ROOM;
void create() {
	set( "short", "$HIR$煉丹房$NOR$" );
	set( "owner", "taa" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room619.c",
		"down"      : "/open/clan/ou-cloud-club/room/room11",
	]) );
	set( "long", @LONG
LONG);
	setup();
	replace_program(ROOM);
}
