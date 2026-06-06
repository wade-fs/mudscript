inherit ROOM;
void create() {
	set( "short", "命運叉路" );
	set( "object", ([
		"amount3"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "build", 10023 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room60.c",
		"west"      : "/open/clan/hell/room/room58.c",
		"hole"      : "/open/clan/hell/room/room61",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

        漸漸清醒之後，發覺自己漂浮在一個詭異的次元當中，四周若有似無
        的奇幻裝備，多次嘗試著去拿取，卻不得其法，這時發現前方似乎有
        兩條通道，凝神往右邊看去，突然一股邪惡氣息上衝，腦中充滿殺戮
        ，轉頭往左邊看去，心中湧出無限的勇氣，全身佈滿一股正義之氣。


LONG);
	setup();
	replace_program(ROOM);
}
