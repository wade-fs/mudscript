inherit ROOM;
void create() {
	set( "short", "開陽堂訓武場" );
	set( "build", 10157 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room502",
	]) );
	set( "long", @LONG
這裡是易水樓中武功更高深的弟子們練功的場所，由於每個人都在
辛勤的練習著劍法、拳法、刀法、棍法，所以空氣中瀰漫著青春的汗水
，不過味道酸酸的，而且空氣中也瀰漫著一陣陣強烈的殺氣跟一陣陣的
死亡氣息，這些殺氣跟氣息向你慢慢的逼進，令你想快點離開這裡。

LONG);
	setup();
	replace_program(ROOM);
}
