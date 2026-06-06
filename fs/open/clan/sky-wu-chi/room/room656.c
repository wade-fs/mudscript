inherit ROOM;
void create() {
	set( "short", "sqr專用 四.." );
	set( "build", 11320 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room639",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"north"     : "/open/clan/sky-wu-chi/room/room655.c",
	]) );
	set( "long", @LONG
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
LONG);
	setup();
	replace_program(ROOM);
}
