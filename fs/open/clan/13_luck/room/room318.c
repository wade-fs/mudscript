inherit ROOM;
void create() {
	set( "short", "吉祥置物櫃己" );
	set( "owner", "atwo" );
	set( "build", 10137 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room306",
	]) );
	set( "long", @LONG

    這裡是吉祥置物櫃己，專門為還沒有房間的新進幫眾所設立的，此
環境優雅舒適，讓新進的幫眾有個可以去的地方跟休息的地方，使他們
快點成為十三吉祥的戰力，一起為幫派的未來而努力，一同打拼，萬里
風雲騏意驥足，百年珠樹鳳凰枝，希望能為天下第一大幫而邁進。

LONG);
	setup();
	replace_program(ROOM);
}
