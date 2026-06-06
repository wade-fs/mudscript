inherit ROOM;
void create() {
	set( "short", "星之金字塔頂樓" );
	set( "exits", ([
		"pass"      : "/open/clan/time-limit/room/room116.c",
		"south"     : "/open/clan/time-limit/room/room259",
	]) );
	set( "long", @LONG
經過千辛萬苦來到頂樓,已經快到終點了,心裡想著即將到手的寶物,提起精神往前走,前方忽
然吹來一陣冷風,迎面而來的是一張熟悉的面孔,來人居然是雙頭龍!雙頭龍不是在冰原裡嗎
仔細一瞧,這個雙頭龍身影有點模糊,應該是被控制的亡魂,不過威力可是不會改變的

LONG);
	setup();
	replace_program(ROOM);
}
