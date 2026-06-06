inherit ROOM;
void create() {
	set( "short", "沙灘" );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room141",
		"west"      : "/open/clan/hell/room/room94.c",
	]) );
	set( "long", @LONG
踏在雪白的沙粒上前進,本該是一件愜意的事,但此刻的你完全沒有這種悠閒
的心情,沙子沿著岸邊的形狀彎彎曲曲的往東邊綿延下去,你運著輕功上面不斷奔
馳著,只想趕快找到進入島上的道路,波浪一波波的打上來,跟你著急的心情一點都
不相稱.

LONG);
	setup();
	replace_program(ROOM);
}
