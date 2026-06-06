inherit ROOM;
void create() {
	set( "short", "吉祥水道" );
	set( "object", ([
		"file5"    : "/daemon/class/blademan/obj/wastone",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount6"  : 1,
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/daemon/class/blademan/obj/fstone",
		"amount5"  : 1,
		"file3"    : "/daemon/class/blademan/obj/estone",
		"amount7"  : 1,
		"file4"    : "/daemon/class/blademan/obj/wstone",
		"file1"    : "/daemon/class/blademan/obj/gstone",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"file9"    : "/daemon/class/blademan/obj/hstone",
		"amount10" : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10329 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/hall.c",
		"west"      : "/open/clan/13_luck/room/room26",
	]) );
	set( "long", @LONG

    當你向前遠望時，你會感到非常高興，因為目的地即將到達，當你
更注意前方的景色時你會覺得好美，在你探聽之下知道那是十三吉祥的
名勝柳月泉，那是十三吉祥的總樞紐，來來往往的幫眾眾多，你會巴不
得趕快下船去柳月泉好好遊玩一般。

LONG);
	setup();
	replace_program(ROOM);
}
