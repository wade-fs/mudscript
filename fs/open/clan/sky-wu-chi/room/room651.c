inherit ROOM;
void create() {
	set( "short", "火行三" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room649",
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
