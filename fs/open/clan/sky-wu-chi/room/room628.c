inherit ROOM;
void create() {
	set( "short", "Ddt-水靈塔一樓" );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room627",
	]) );
	set( "long", @LONG
全部都是水阿全部都是水阿全部都是水阿全部都是水阿全部都是水阿
全部都是水阿全部都是水阿全部都是水阿全部都是水阿全部都是水阿
全部都是水阿全部都是水阿全部都是水阿全部都是水阿全部都是水阿
全部都是水阿全部都是水阿全部都是水阿全部都是水阿全部都是水阿
全部都是水阿全部都是水阿全部都是水阿全部都是水阿全部都是水阿
LONG);
	setup();
	replace_program(ROOM);
}
