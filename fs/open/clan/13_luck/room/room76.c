inherit ROOM;
void create() {
	set( "short", "煙雨樓六樓" );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room71.c",
		"north"     : "/open/clan/13_luck/room/room79.c",
		"west"      : "/open/clan/13_luck/room/room340",
		"up"        : "/open/clan/13_luck/room/room83.c",
		"east"      : "/open/clan/13_luck/room/room77.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官歡迎您來到煙雨樓六樓，您所定下的廂房已經清理乾淨了。
從房內的窗戶往外看可以將十三吉祥的全貌盡收眼底，往東南邊看去
，妳看到那也是燈火通明，感覺的出來那邊是非常熱鬧的地方，詢問
了一下店小二，確定那而是十三吉祥最熱鬧的地方『日郡』。

LONG);
	setup();
	replace_program(ROOM);
}
