inherit ROOM;
void create() {
	set( "short", "$HIR$魁$HIG$地$HIY$奇$HIB$球$HIM$場$NOR$" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room73",
	]) );
	set( "long", @LONG
魁地奇是魔法世界最風行的運動,由巫師騎著飛天掃帚來比賽,而每次比賽時,
看台就會被熱情的觀眾擠爆,紛紛為自己所屬的學院加油,平時則由各學院
安排時間練習,'哈利波特'正和葛來分多代表隊練習一種新戰術,
只看哈利騎著火閃電飛來飛去,不一會就捉到金探子了

LONG);
	setup();
	replace_program(ROOM);
}
