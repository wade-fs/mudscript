inherit ROOM;
void create() {
	set( "short", "煙雨樓三樓" );
	set( "build", 60 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room148",
		"north"     : "/open/clan/13_luck/room/room61.c",
		"down"      : "/open/clan/13_luck/room/room53",
		"east"      : "/open/clan/13_luck/room/room59.c",
		"south"     : "/open/clan/13_luck/room/room66.c",
		"up"        : "/open/clan/13_luck/room/room71.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官歡迎您來到煙雨樓三樓，您所定下的廂房已經清理乾淨了。
從房內的窗戶往外看可以將十三吉祥的全貌盡收眼底，往北邊看去，
妳看到有一條白色的迷霧衝往天際，妳很好奇那到底通往哪呢？今天
晚上先好好的睡一覺，明天再去一看究竟。

LONG);
	setup();
	replace_program(ROOM);
}
