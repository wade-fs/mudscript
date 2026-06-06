inherit ROOM;
void create() {
	set( "short", "醉仙樓大堂" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room610",
		"east"      : "/open/clan/13_luck/room/room612.c",
		"south"     : "/open/clan/13_luck/room/room611.c",
		"west"      : "/open/clan/13_luck/room/room614",
	]) );
	set( "long", @LONG
這是醉仙樓大堂，來來往往的人客和跑堂小二，夾雜著三個宴會廳
刺耳的呼叫聲，碰杯聲，打鬧聲，賴酒聲，熱鬧非凡。你在三個宴會廳
前打量著進哪個湊個熱鬧，蹭點白食。
    東邊是玫瑰廳，朝南的是牡丹廳，向北是芙蓉廳。
LONG);
	setup();
	replace_program(ROOM);
}
