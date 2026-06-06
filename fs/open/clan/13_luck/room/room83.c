inherit ROOM;
void create() {
	set( "short", "煙雨樓七樓" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room81.c",
		"up"        : "/open/clan/13_luck/room/room90.c",
		"north"     : "/open/clan/13_luck/room/room86.c",
		"down"      : "/open/clan/13_luck/room/room76.c",
		"west"      : "/open/clan/13_luck/room/room89.c",
		"east"      : "/open/clan/13_luck/room/room84.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官歡迎您來到煙雨樓七樓，您所定下的廂房已經清理乾淨了。
從房內的窗戶往外看可以將十三吉祥的全貌盡收眼底，在漫長的夜晚
，也不知要做些什麼，突發奇想就跟店小二叫個叉燒炒飯，沒想到這
兒不但風景美，連『炒飯』都這麼美味可口。

LONG);
	setup();
	replace_program(ROOM);
}
