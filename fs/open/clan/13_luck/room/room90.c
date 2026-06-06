inherit ROOM;
void create() {
	set( "short", "煙雨樓八樓" );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room94.c",
		"south"     : "/open/clan/13_luck/room/room91.c",
		"east"      : "/open/clan/13_luck/room/room73.c",
		"north"     : "/open/clan/13_luck/room/room93.c",
		"down"      : "/open/clan/13_luck/room/room83.c",
	]) );
	set( "long", @LONG

    客官歡迎您來到煙雨樓八樓，您所定下的廂房已經清理乾淨了。
從房內的窗戶往外看可以將十三吉祥的全貌盡收眼底，整個ＦＳ大陸
沒有一個大樓能比十三吉祥的這三棟大樓更高更美的，全都花費了數
年的時間設計，能住在這裡一天不知幾年來修來的福分。

LONG);
	setup();
	replace_program(ROOM);
}
