inherit ROOM;
void create() {
	set( "short", "望月樓三樓" );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room592.c",
		"south"     : "/open/clan/13_luck/room/room690.c",
		"west"      : "/open/clan/13_luck/room/room648.c",
		"north"     : "/open/clan/13_luck/room/room589.c",
		"down"      : "/open/clan/13_luck/room/room594.c",
	]) );
	set( "long", @LONG

    你正走在望月樓三樓的走廊上，店小二裏裏外外正忙得團團轉。
倚靠著欄杆，望向十三吉祥的街道去，路上行人來來往往熱鬧非常，
足見十三吉祥的治安非常的良好。還有那可愛的孩童也成群地在路旁
嘻戲，讓你不時回想起你童年的美麗回憶。

LONG);
	setup();
	replace_program(ROOM);
}
