inherit ROOM;
void create() {
	set( "short", "sqr專用.." );
	set( "build", 10485 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room641",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "long", @LONG
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
LONG);
	setup();
	replace_program(ROOM);
}
