inherit ROOM;
void create() {
	set( "short", "大門會客室" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"file9"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10287 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room284",
	]) );
	set( "long", @LONG
會客大門..除了每天有人擔心兒子安全會來會客外..這裡可
說是禁閉室的地方..關著在軍中犯錯而情節重大還不能判軍法的
人..但有些變態的長官就例外了..曾經有人跑三千落隊也有被抓
去關的..這一種是變態的旅長..心裡不正常..避之避之..
LONG);
	setup();
	replace_program(ROOM);
}
