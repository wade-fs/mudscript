inherit ROOM;
void create() {
	set( "short", "前廳二" );
	set( "build", 10149 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room523.c",
		"north"     : "/open/clan/13_luck/room/room517",
		"east"      : "/open/clan/13_luck/room/room525.c",
	]) );
	set( "long", @LONG
你被這裡的一股莫名的氣勢震住了，它簡直就像一座宮殿般的富麗
堂皇，而其華麗的裝飾下卻也不失沉穩內斂，微微檀香傳來，令你的心
情不自覺的平靜和緩，與世無爭的感覺油然而生。前方就是大廳了，你
禁不住的緊張，深呼一口氣，向前走去。就在你要踏入大廳之時，一陣
殺氣從大廳裡散發出來。
LONG);
	setup();
	replace_program(ROOM);
}
