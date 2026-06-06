inherit ROOM;
void create() {
	set( "short", "庭外長廊" );
	set( "owner", "roarii" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room599",
		"south"     : "/open/clan/13_luck/room/room601",
	]) );
	set( "long", @LONG
現在你位於聖堂中庭外的長廊上，兩旁的假山假水十分
地美麗，花園之中百花盛開互相爭奇鬥豔。這些花全部都是
聖堂堂主之妻所親手栽培的！這個美麗花園帶來的柔和之氣
和聖堂所散發的陽剛之氣相對比，簡直是將聖堂的氣場調和
一番，看來聖堂夫人還真是有心！

LONG);
	setup();
	replace_program(ROOM);
}
