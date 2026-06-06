inherit ROOM;
void create() {
	set( "short", "五行區二" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room622.c",
		"west"      : "/open/clan/sky-wu-chi/room/room644.c",
		"east"      : "/open/clan/sky-wu-chi/room/room649",
	]) );
	set( "long", @LONG
懶的寫....................................................
懶的寫....................................................
懶的寫....................................................
懶的寫....................................................
懶的寫....................................................
LONG);
	setup();
	replace_program(ROOM);
}
