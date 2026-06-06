inherit ROOM;
void create() {
	set( "short", "$BWHT$休息室$NOR$" );
	set( "build", 8946 );
	set( "owner", "kerr" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room77",
	]) );
	set( "long", @LONG
在廠務大樓裡竟還有這種地方, 一入眼簾投影式布幕正撥放著電影, 立體的音響
設備把電影的情節生動描述, 右邊還有撞球桌, 桌球桌, 左邊有寬敞的沙發以及
閱讀室, 最特別的應該是在機房旁邊竟然能有一塊如此安靜的地方, 一進到這邊
讓你都忘了工作的憂煩. 

LONG);
	setup();
	replace_program(ROOM);
}
