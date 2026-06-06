inherit ROOM;
void create() {
	set( "short", "Ddt-木靈塔一樓" );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room627",
	]) );
	set( "long", @LONG
一遍遍蒼鬱的樹海，妳舉目所見就是一遍的樹
木木木木木木木木木木木木木木木木木木木木木木木木木木木
木木木木木木木木木木木木木木木木木木木木木木木木木木木
木木木木木木木木木木木木木木木木木木木木木木木木木木木
木木木木木木木木木木木木木木木木木木木木木木木木木木木
LONG);
	setup();
	replace_program(ROOM);
}
