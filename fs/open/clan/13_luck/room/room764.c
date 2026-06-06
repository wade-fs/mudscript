inherit ROOM;
void create() {
	set( "short", "大頭兵冥王裝備房" );
	set( "build", 10065 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room763",
	]) );
	set( "owner", "adeyzit" );
	set( "long", @LONG
一進入這房間，你眼前一片眼花花阿，一堆冥王裝備，一整堆的冥王
裝備被放到這邊，讓你不經想要偷偷的拿上個一、兩件好增強自己的
實力，可是你又害怕會被大頭兵拿T91步槍掃射，還是放下這個唸頭
吧。房間之亂都讓你起了這裡不見了一兩件應該不會有人發現吧。
LONG);
	setup();
	replace_program(ROOM);
}
