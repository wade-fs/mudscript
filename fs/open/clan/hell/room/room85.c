inherit ROOM;
void create() {
	set( "short", "$YEL$靈氣土珠$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/soil-ball",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/soil-ball",
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/obj/soil-ball",
	]) );
	set( "light_up", 1 );
	set( "build", 11002 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room86",
	]) );
	set( "long", @LONG
相傳如果要進入五行靈塔，就必需要攜帶的寶物，靈氣土珠所散
發出來的靈氣，足以克制五行之中的水靈之氣，可以減少具有傷害的
靈氣所帶來之傷害。靈氣土珠必需要聚靈之後，才會開啟其作用，若
尚未聚靈的靈氣土珠是無任何作用的。
所以陰曹地府天兵天將們在闖塔前,記得帶一顆吧!!

LONG);
	setup();
	replace_program(ROOM);
}
