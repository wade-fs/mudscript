inherit ROOM;
void create() {
	set( "short", "Ddt-金靈塔一樓 " );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room627",
	]) );
	set( "long", @LONG
全部都是金子阿全部都是金子阿全部都是金子阿全部都是金子阿
全部都是金子阿全部都是金子阿全部都是金子阿全部都是金子阿
全部都是金子阿全部都是金子阿全部都是金子阿全部都是金子阿
全部都是金子阿全部都是金子阿全部都是金子阿全部都是金子阿
全部都是金子阿全部都是金子阿全部都是金子阿全部都是金子阿
LONG);
	setup();
	replace_program(ROOM);
}
