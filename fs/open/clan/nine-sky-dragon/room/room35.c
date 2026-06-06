inherit ROOM;
void create() {
	set( "short", "醉仙樓五樓" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/nine-sky-dragon/room/room13",
		"up"        : "/open/clan/nine-sky-dragon/room/room36",
	]) );
	set( "long", @LONG

　　你繞過一道淡綠綢屏風，順著樓梯來到醉仙樓五樓的走郎上，心
情愉悅地走著。樓下大廳那從來店小二招呼客人的聲音和客人們飲酒
做樂的笑聲。夕陽西下，倚靠在窗戶邊，望天滿天雲彩，只見滿天飛
鳥，也都要回巢穴去休息了。

LONG);
	setup();
	replace_program(ROOM);
}
