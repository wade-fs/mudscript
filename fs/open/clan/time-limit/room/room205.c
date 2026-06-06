inherit ROOM;
void create() {
	set( "short", "月之金字塔頂樓" );
	set( "exits", ([
		"pass"      : "/open/clan/time-limit/room/room116",
		"south"     : "/open/clan/time-limit/room/room206",
	]) );
	set( "long", @LONG
經過千辛萬苦來到頂樓,已經快到終點了,心裡想著即將到手的寶物提起精神往前走,前方忽
然一股陰冷的氣息直逼而來,迎面而來的是一張熟悉的面孔,來人居然是死靈骨魔!死靈骨魔
不是在死靈幽谷裡嗎仔細一瞧,這個死靈骨魔身影有點模糊,應該是被控制的亡魂,不過威力
可是不會改變的

LONG);
	setup();
	replace_program(ROOM);
}
