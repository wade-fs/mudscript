inherit ROOM;
void create() {
	set( "short", "血痕居-黑繩地獄" );
	set( "owner", "holeman" );
	set( "build", 10204 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room533.c",
		"south"     : "/open/clan/sky-wu-chi/room/room535",
		"east"      : "/open/clan/sky-wu-chi/room/room528.c",
	]) );
	set( "long", @LONG

    在極度炎熱的鐵地上，閻羅的獄卒會用黑繩在每個眾生身上量
身畫線，然後用火紅的刀，依量線切割他們的身體。切開之後的身
，就這樣反復的感受切割時所帶來的痛苦。

    他們的壽命是：人間的一百年為三十三天的一天，三十三天的
一千年，是黑繩地獄的一天，他們要在這裡受一千年的痛苦。


LONG);
	setup();
	replace_program(ROOM);
}
