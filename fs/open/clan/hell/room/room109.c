inherit ROOM;
void create() {
	set( "short", "浪翻雲的石屋" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/hell/room/room127",
		"east"      : "/open/clan/hell/room/room108.c",
	]) );
	set( "long", @LONG
一所築在怒蛟島南一個小山谷內的石屋。這是島上最僻靜的地方
，一里內再無其他人家。兼且石屋藏在山谷的盡頭，屋前小橋流水，
非常幽雅。
萬里入無徑，千峰掩一籬。
屋前的小窗，因為山勢頗高，恰好看到一小截洞庭湖的湖水。
洞庭湖潮水漲退的聲音，隱隱可聞。
LONG);
	setup();
	replace_program(ROOM);
}
