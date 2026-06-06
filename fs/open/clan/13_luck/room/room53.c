inherit ROOM;
void create() {
	set( "short", "煙雨樓二樓" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room55.c",
		"north"     : "/open/clan/13_luck/room/room57.c",
		"up"        : "/open/clan/13_luck/room/room54.c",
		"down"      : "/open/clan/13_luck/room/room43.c",
		"south"     : "/open/clan/13_luck/room/room58.c",
		"west"      : "/open/clan/13_luck/room/room95",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官歡迎您來到煙雨樓二樓，您所定下的廂房已經清理乾淨了。
從房內的窗戶往外看可以將十三吉祥的全貌盡收眼底，從早到晚燈火
通明，就算晚上睡覺大門不關也不會有小偷，在幫主小南的領導下，
十三吉祥已開始走向全盛時期了。

LONG);
	setup();
	replace_program(ROOM);
}
