inherit ROOM;
void create() {
	set( "short", "北大街" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room617",
		"up"        : "/open/clan/13_luck/room/room105",
	]) );
	set( "long", @LONG
你走在在一條繁忙的街道上，看著操著南腔北調的人們行色匆匆，許多
人都往南邊走去，那裏有一個熱鬧的廣場。東邊是一家生意興隆的客棧，來
自各地的人們進進出出，據說也是情人們的幽會地點。西邊是一家錢莊，可
以聽到叮叮當當的金銀聲音。
LONG);
	setup();
	replace_program(ROOM);
}
