inherit ROOM;
void create() {
	set( "short", "白鶴泉" );
	set( "owner", "poll" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room606",
		"east"      : "/open/clan/13_luck/room/room604",
	]) );
	set( "long", @LONG
相傳從前這裏有一個白鶴泉，它的水清涼甘甜，為泰山之最。
這泉水長年湧流不斷，噴出的水象仙鶴撲扇著翅膀洗澡一樣，因以
為名。可惜後來有一個自私自利的小官，獨霸了泉水，後來更因迷
信風水之說，把泉眼堵塞，白鶴泉從此便幹涸了。現在只剩下一座
刻著「白鶴泉」三字的石坊以為紀念。從這裏繼續北上，便是上山
之路。
LONG);
	setup();
	replace_program(ROOM);
}
