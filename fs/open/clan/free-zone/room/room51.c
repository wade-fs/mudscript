inherit ROOM;
void create() {
	set( "short", "魔刀煉房" );
	set( "build", 10626 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room50",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├魔┤☆☆├刀┤☆☆├煉┤☆☆├房┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★

LONG);
	setup();
	replace_program(ROOM);
}
