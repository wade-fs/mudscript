inherit ROOM;
void create() {
	set( "short", "火行一" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room651.c",
		"north"     : "/open/clan/sky-wu-chi/room/room650.c",
		"west"      : "/open/clan/sky-wu-chi/room/room642",
		"east"      : "/open/clan/sky-wu-chi/room/room652",
	]) );
	set( "long", @LONG
不想寫了啦.......................................> < 
不想寫了啦.......................................> < 
不想寫了啦.......................................> < 
不想寫了啦.......................................> < 
LONG);
	setup();
	replace_program(ROOM);
}
