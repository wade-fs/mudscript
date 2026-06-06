inherit ROOM;
void create() {
	set( "short", "一樓走道" );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room225",
		"out"       : "/open/clan/13_luck/room/room227.c",
	]) );
	set( "long", @LONG

　　你小心異異的走在龍塔之中，裡面的石壁排列幾乎都是同一個樣
子，一不小心就會迷失其中，看來不小心是不行了，正當你左右顧盼
，小心翼翼往前繼續前進之時，突然三道影子向你俯衝而來，擋住你
的去路，定神一看，天ㄚ～竟然是幼龍！！

LONG);
	setup();
	replace_program(ROOM);
}
