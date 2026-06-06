inherit ROOM;
void create() {
	set( "short", "刀房" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount2"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 9864 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room391",
	]) );
	set( "long", @LONG

    這裡是十三刀堂的刀具供應室，只要是羅剎的一份子，就可以來這裡
取得基本可使用的刀，這裡的管理者會發給你你可以拿到的刀，這種刀威
力可能不強，但是它絕對夠你在江湖上使用，除此之外，牆上還掛著其它
很多江湖上的名刀，多半是當初逃進十三吉祥的刀客所帶進來的

LONG);
	setup();
	replace_program(ROOM);
}
