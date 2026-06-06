inherit ROOM;
void create() {
	set( "short", "沙漠棧道" );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/sun-heart",
		"amount1"  : 1,
	]) );
	set( "owner", "zmud" );
	set( "build", 10002 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room478",
	]) );
	set( "long", @LONG

    一看到前方沙漠的人，只有百分之十可能會想要通過，而在這百分
之十中則有百分之百的人會想要先吃飽了，再渡過這個沙漠，當然沒有
想要通過的百分之九十中，更有不少人想說，來了都來了，就吃飽了再
回去，至少也比就有精神，由此可知這間小店的生意有多好了。

LONG);
	setup();
	replace_program(ROOM);
}
