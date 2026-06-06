inherit ROOM;
void create() {
	set( "short", "煙雨樓五樓" );
	set( "build", 27 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room354.c",
		"south"     : "/open/clan/13_luck/room/room74.c",
		"west"      : "/open/clan/13_luck/room/room44",
		"up"        : "/open/clan/13_luck/room/room76.c",
		"north"     : "/open/clan/13_luck/room/room75.c",
		"down"      : "/open/clan/13_luck/room/room54.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官歡迎您來到煙雨樓五樓，您所定下的廂房已經清理乾淨了。
從房內的窗戶往外看可以將十三吉祥的全貌盡收眼底，到了晚上時，
涼涼的徐風吹來，輕輕的打在臉頰上猶如按摩皮膚一般的舒服，吹著
微風吃著小點心，也是別有一般風趣。

LONG);
	setup();
	replace_program(ROOM);
}
