inherit ROOM;
void create() {
	set( "short", "鳳凰樓七樓" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room347.c",
		"north"     : "/open/clan/13_luck/room/room536.c",
		"up"        : "/open/clan/13_luck/room/room670.c",
		"west"      : "/open/clan/13_luck/room/room529.c",
		"east"      : "/open/clan/13_luck/room/room732",
		"down"      : "/open/clan/13_luck/room/room100",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

　　在店小二的引領，你沿著燈火照亮的樓梯往上爬，來到了鳳凰樓
七樓的通道，往你的廂房走去。夜裡，徐徐的涼風吹來，真是舒暢。
傾靠在護欄上靜靜的欣賞美麗的夜景，暫時忘卻一切煩惱，欣賞這美
麗的夜景真是人間一大樂事。


LONG);
	setup();
	replace_program(ROOM);
}
