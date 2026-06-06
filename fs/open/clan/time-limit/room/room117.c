inherit ROOM;
void create() {
	set( "short", "日之金字塔頂樓" );
	set( "exits", ([
		"pass"      : "/open/clan/time-limit/room/room116",
		"south"     : "/open/clan/time-limit/room/room118.c",
	]) );
	set( "long", @LONG
經過千辛萬苦來到頂樓,已經快到終點了,心裡想著即將到手的寶物,提起精神往前走,前方忽
然火光四射,迎面而來的是一張熟悉的面孔,來人居然是焚天魔王!焚天魔王不是在妖靈古堡
裡嗎仔細一瞧,這個焚天魔王身影有點模糊,應該是被控制的亡魂,不過威力可是不會改變的

LONG);
	setup();
	replace_program(ROOM);
}
