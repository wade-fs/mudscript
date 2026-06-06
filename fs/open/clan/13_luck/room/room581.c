inherit ROOM;
void create() {
	set( "short", "望月樓六樓" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room592",
		"north"     : "/open/clan/13_luck/room/room726.c",
		"west"      : "/open/clan/13_luck/room/room724",
		"up"        : "/open/clan/13_luck/room/room580",
		"south"     : "/open/clan/13_luck/room/room722.c",
		"east"      : "/open/clan/13_luck/room/room725",
	]) );
	set( "long", @LONG

    你正走在望月樓六樓的走廊上，店小二裏裏外外正忙得團團轉。
進到房間，發現房裡異常的溫暖，牆角壁爐裏微弱的火光將你的影子
投射在對面的牆上。隔壁房裡不時傳來講話聲，似乎在討論些什麼。
一切看來非常的詳和寧靜，你幾乎忘了自己身在何處。

LONG);
	setup();
	replace_program(ROOM);
}
