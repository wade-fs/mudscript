inherit ROOM;
void create() {
	set( "short", "鳳凰樓" );
	set( "build", 422 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room98",
		"out"       : "/open/clan/13_luck/room/room41.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是是十三吉祥的客棧左廳『鳳凰樓』，也是裝飾最為華麗非
凡，大門口掛著鑽石做的牌匾閃閃發亮，令你忍不住多看幾眼，兩根
門柱上的鳳凰雕刻的栩栩如生，在往裡面望去大廳中央壁上掛著一幅
龍鳳呈祥，顯的氣派非凡。

LONG);
	setup();
	replace_program(ROOM);
}
