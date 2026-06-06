inherit ROOM;
void create() {
	set( "short", "$HIR$靈氣火珠$NOR$" );
	set( "object", ([
		"file5"    : "/open/gsword/obj1/sball",
		"file1"    : "/open/magic-manor/obj/fire-ball",
		"amount1"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/obj/fire-ball",
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/obj/fire-ball",
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/obj/fire-ball",
		"file6"    : "/open/magic-manor/obj/fire-ball",
		"amount4"  : 1,
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10111 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room86",
	]) );
	set( "long", @LONG
相傳如果要進入五行靈塔，就必需要攜帶的寶物，靈氣火珠所散
發出來的靈氣，足以克制五行之中的金靈之氣，可以減少具有傷害的
靈氣所帶來之傷害。靈氣火珠必需要聚靈之後，才會開啟其作用，若
尚未聚靈的靈氣火珠是無任何作用的。
所以陰曹地府天兵天將們在闖塔前,記得帶一顆吧!!

LONG);
	setup();
	replace_program(ROOM);
}
