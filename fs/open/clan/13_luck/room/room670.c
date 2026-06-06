inherit ROOM;
void create() {
	set( "short", "鳳凰樓八樓" );
	set( "build", 442 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room342.c",
		"south"     : "/open/clan/13_luck/room/room730",
		"east"      : "/open/clan/13_luck/room/room729.c",
		"west"      : "/open/clan/13_luck/room/room731.c",
	]) );
	set( "long", @LONG

        　　在店小二的引領，你沿著燈火照亮的樓梯往上爬，來到了鳳凰樓
八樓的通道，往你的援裡，徐徐的涼風吹來，真是舒暢。
傾靠在護欄上仰望著明月以及滿天的星斗，暫時忘卻一切煩惱，忘卻
一切的鬥爭，靜靜的欣賞美麗的夜景。

LONG);
	setup();
	replace_program(ROOM);
}
