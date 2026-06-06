inherit ROOM;
void create() {
	set( "short", "御劍軒" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room631",
		"out"       : "/open/clan/13_luck/room/room633",
	]) );
	set( "long", @LONG

    御劍軒為詩劍山莊南邊的守護屏障，陣陣梅花的香氣，隨著清風令
人神清氣爽，有的弟子盤腿靜坐體悟著身體裡那股暖暖的熱流，有的輕
輕舞劍，緩緩的試招，感覺起來像是慢動作，但是卻令人清楚的知道，
他們正將某種意境融入那輕輕緩緩的劍式裡‧

LONG);
	setup();
	replace_program(ROOM);
}
