inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIC$４$NOR$" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/black-ghost-head",
		"amount1"  : 1,
	]) );
	set( "build", 10196 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room705.c",
		"south"     : "/open/clan/ou-cloud-club/room/room710.c",
		"north"     : "/open/clan/ou-cloud-club/room/room714",
	]) );
	set( "long", @LONG
黑羅剎的人頭黑羅剎的人頭
　　黑羅剎的人頭黑羅剎的人頭
　　黑羅剎的人頭黑羅剎的人頭
　　黑羅剎的人頭黑羅剎的人頭
　　黑羅剎的人頭黑羅剎的人頭
　　黑羅剎的人頭黑羅剎的人頭
　　黑羅剎的人頭黑羅剎的人頭
　　黑羅剎的人頭黑羅剎的人頭
　　黑羅剎的人頭黑羅剎的人頭
　　黑羅剎的人頭黑羅剎的人頭

LONG);
	setup();
	replace_program(ROOM);
}
