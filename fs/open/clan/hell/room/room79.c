inherit ROOM;
void create() {
	set( "short", "$HIC$靈氣水珠$NOR$" );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/water-ball",
		"amount2"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/water-ball",
	]) );
	set( "build", 10090 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room86",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
相傳如果要進入五行靈塔，就必需要攜帶的寶物，靈氣水珠所散
發出來的靈氣，足以克制五行之中的火靈之氣，可以減少具有傷害的
靈氣所帶來之傷害。靈氣水珠必需要聚靈之後，才會開啟其作用，若
尚未聚靈的靈氣水珠是無任何作用的。
所以陰曹地府天兵天將們在闖塔前,記得帶一顆吧!!

LONG);
	setup();
	replace_program(ROOM);
}
