inherit ROOM;
void create() {
	set( "short", "$HIC$邪月迴廊$NOR$" );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room211",
		"east"      : "/open/clan/sky-wu-chi/room/room191.c",
		"south"     : "/open/clan/sky-wu-chi/room/room181.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
      走進這裡,便見一座香煙裊裊的大香爐坐落於廣大的大廳之中
爐內飄出了一陣陣讓你精神氣爽的白煙,使你驚訝的是,原來這是
天道無極幫主~~~刀神燕仔以內力所激發出來的...........

<----艾尼斯小窩   卡卡西的小套房---->

LONG);
	setup();
	replace_program(ROOM);
}
