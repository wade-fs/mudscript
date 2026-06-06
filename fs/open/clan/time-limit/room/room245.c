inherit ROOM;
void create() {
	set( "short", "$CYN$無$YEL$慾$MAG$天$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room198",
	]) );
	set( "long", @LONG
無慾天正是脫俗仙子談無慾的住所,與日才子素還真齊名的月才子談無慾,興趣是泡茶與
下棋,前方不遠的涼亭裡就擺著一付棋盤,仔細一看,這些棋子都是用石頭刻成的,一般人
無法輕易移動棋子,也就表示能下這棋盤的人必定是功力深厚,一旁的欄杆可以遠望山下
的景色,也能看到上下無慾天的人們,而做好接待與防敵的準備

LONG);
	setup();
	replace_program(ROOM);
}
