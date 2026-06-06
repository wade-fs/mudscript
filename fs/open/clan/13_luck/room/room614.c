inherit ROOM;
void create() {
	set( "short", "醉仙樓二樓" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room615.c",
		"east"      : "/open/clan/13_luck/room/room613",
	]) );
	set( "long", @LONG
這裏是雅座，文人學士經常在這裏吟詩作畫，富商土豪也在這裏邊吃喝
邊作交易。這裏也是城裏舉辦喜宴的最佳場所。你站在樓上眺望，只覺得心
曠神怡。東面是一池湖水，碧波蕩漾。北面是崇山峻嶺，而南面可以看到聞
名全國的白鹿書院的後庭。牆上掛著價格牌子(paizi)。
LONG);
	setup();
	replace_program(ROOM);
}
