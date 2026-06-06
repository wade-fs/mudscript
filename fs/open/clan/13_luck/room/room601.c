inherit ROOM;
void create() {
	set( "short", "聖堂玄關" );
	set( "owner", "roarii" );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room602",
		"north"     : "/open/clan/13_luck/room/room600",
	]) );
	set( "long", @LONG
你現在來到了聖堂的玄關，你在這裡看見了一名身穿素
色獨臂的中年男子，他正是聖堂四守之一的聖˙絕名！他負
責在玄關鎮守想闖入聖堂搗亂的人。在玄關這裡可以看見大
部分聖堂的樓閣。往西北方看，那棟雄偉建築就是聖堂主樓
－刑天樓！

LONG);
	setup();
	replace_program(ROOM);
}
