inherit ROOM;
void create() {
	set( "short", "$HIC$邪月迴廊$HIY$大門$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room177.c",
		"north"     : "/open/clan/sky-wu-chi/room/room180",
	]) );
	set( "long", @LONG
走進這裡,便見一座香煙裊裊的大香爐坐落於廣大的大廳之中
爐內飄出了一陣陣讓你精神氣爽的白煙,使你驚訝的是,原來這是
天道無極幫主~~~刀神燕仔以內力所激發出來的...........
LONG);
	setup();
	replace_program(ROOM);
}
