inherit ROOM;
void create() {
	set( "short", "Ddt-火靈塔一樓" );
	set( "owner", "marshal" );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room627",
	]) );
	set( "long", @LONG
一大遍的火盲目了你的眼睛，你看到的就是無盡的火海
火火火火火火火火火火火火火火火火火火火火火火火火火火火火
火火火火火火火火火火火火火火火火火火火火火火火火火火火火
火火火火火火火火火火火火火火火火火火火火火火火火火火火火
火火火火火火火火火火火火火火火火火火火火火火火火火火火火
火火火火火火火火火火火火火火火火火火火火火火火火火火火火
LONG);
	setup();
	replace_program(ROOM);
}
