inherit ROOM;
void create() {
	set( "short", "望月樓七樓" );
	set( "build", 12 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room581",
		"south"     : "/open/clan/13_luck/room/room733",
		"west"      : "/open/clan/13_luck/room/room10",
		"east"      : "/open/clan/13_luck/room/room728.c",
		"north"     : "/open/clan/13_luck/room/room727",
	]) );
	set( "long", @LONG

    你正走在望月樓七樓的走廊上，店小二裏裏外外正忙得團團轉。
一大早醒來，深呼一口氣，只覺空氣十分清新，似乎還帶點甜甜的味
道。你坐在房裡，享受這清晨特有的寧靜，聆聽屋外那早起鳥兒的啼
叫聲，好不愜意。

LONG);
	setup();
	replace_program(ROOM);
}
