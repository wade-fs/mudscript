inherit ROOM;
void create() {
	set( "short", "鳳凰樓六樓" );
	set( "build", 18 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room676",
		"west"      : "/open/clan/13_luck/room/room236.c",
		"down"      : "/open/clan/13_luck/room/room101.c",
		"up"        : "/open/clan/13_luck/room/room342.c",
		"south"     : "/open/clan/13_luck/room/room265.c",
		"north"     : "/open/clan/13_luck/room/room537.c",
	]) );
	set( "long", @LONG

　　在店小二的引領，你沿著燈火照亮的樓梯往上爬，來到了鳳凰樓
六樓的通道，往你的廂房走去。夜裡，徐徐的涼風吹來，真是舒暢。
傾靠在護欄上仰望著明月以及滿天的星斗，暫時忘卻一切煩惱，忘卻
一切的鬥爭，靜靜的欣賞美麗的夜景。

LONG);
	setup();
	replace_program(ROOM);
}
