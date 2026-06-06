inherit ROOM;
void create() {
	set( "short", "$HIW$當舖$HIC$窗外$NOR$" );
	set( "owner", "yuki" );
	set( "build", 10030 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room540",
		"east"      : "/open/clan/sky-wu-chi/room/room192.c",
	]) );
	set( "long", @LONG
這裡有個小小的窗戶，但是窗外確是沒有任何景色，反而陷入了
一片的渾沌，漫無邊際的黑色涵蓋了窗外，一絲絲的陽光都無法從窗外
射入，瀰漫著陰暗的氣氛彷彿孤立在無盡的深淵，如此的情境使你久久
無法自拔．．．讓你冒出了一身冷汗！
LONG);
	setup();
	replace_program(ROOM);
}
