inherit ROOM;
void create() {
	set( "short", "港口" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room35.c",
		"out"       : "/open/clan/13_luck/room/room150",
	]) );
	set( "long", @LONG

    這裡是可以搭船去十三吉祥的唯一水路，港口邊停了幾艘小船，
妳向船家租了一艘船，當妳準備要啟程時，你看了看海面上的波浪，
發現似乎好像有一定的規律，妳猜想著難道這片海有被下過陣法，在
想一想，或許依著這些固定規律就可以找到出口了。

LONG);
	setup();
	replace_program(ROOM);
}
