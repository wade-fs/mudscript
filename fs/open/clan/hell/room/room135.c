inherit ROOM;
void create() {
	set( "short", "礁石群" );
	set( "exits", ([
		"up"        : "/open/clan/hell/room/room142",
	]) );
	set( "long", @LONG
海水就在腳邊不斷的拍上拍下,強大的衝力好像隨時要把你捲入海中,腳下的
礁石孤獨的矗立在海水之中,每日在漲潮退潮之中不斷地被重複被淹沒的命運,不
遠處另有一塊比較高大的岩石,似乎可以攀到岸上,為了不被滅頂的危險,還是趕快
上去吧.

LONG);
	setup();
	replace_program(ROOM);
}
