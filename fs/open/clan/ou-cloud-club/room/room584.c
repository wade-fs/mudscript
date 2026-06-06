inherit ROOM;
void create() {
	set( "short", "來到西" );
	set( "object", ([
		"file1"    : "/open/capital/obj/blade2",
		"amount1"  : 1,
	]) );
	set( "owner", "dking" );
	set( "build", 10026 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room565",
	]) );
	set( "long", @LONG
這裡是西邊 這裡是西邊 這裡是西邊 這裡是西邊
這裡是西邊 這裡是西邊 這裡是西邊 這裡是西邊
這裡是西邊 這裡是西邊 這裡是西邊 這裡是西邊
這裡是西邊 這裡是西邊 這裡是西邊 這裡是西邊
這裡是西邊 這裡是西邊 這裡是西邊 這裡是西邊
這裡是西邊 這裡是西邊 這裡是西邊 這裡是西邊

LONG);
	setup();
	replace_program(ROOM);
}
