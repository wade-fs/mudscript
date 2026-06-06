inherit ROOM;
void create() {
	set( "short", "霧之林" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room163",
		"south"     : "/open/clan/13_luck/room/room158.c",
		"north"     : "/open/clan/13_luck/room/room166.c",
		"west"      : "/open/clan/13_luck/room/room163.c",
	]) );
	set( "long", @LONG

　　謎樣般的森林，終年濃霧不散，眼前只見白茫茫的一大片，伸手
不見五指。空氣中飄散著奇異的腥味，可是你找不到腥味的來源，迷
迷茫茫地看不到遠方的景觀，萬籟寂靜中，背脊感到一陣涼意，背後
似乎有人正盯著你看。

LONG);
	setup();
	replace_program(ROOM);
}
