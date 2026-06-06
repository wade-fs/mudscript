inherit ROOM;
void create() {
	set( "short", "sqr專用 五.." );
	set( "build", 18918 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room656",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述趕快補敘述
,
LONG);
	setup();
	replace_program(ROOM);
}
