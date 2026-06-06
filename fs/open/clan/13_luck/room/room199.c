inherit ROOM;
void create() {
	set( "short", "鎖龍塔頂" );
	set( "light_up", 1 );
	set( "exits", ([
		"ball"      : "/open/clan/13_luck/room/room198",
		"down"      : "/open/clan/13_luck/room/room200",
	]) );
	set( "long", @LONG

　　經歷過層層關卡你終於到了頂樓，傳說鎖龍塔塔頂正是通往天界
，不過從來沒人知道如何進去的方法，因為從未有人連過九關來到此
處，看著地上怖滿的蛛網可想而知，此地已有好尹(ball)正發出一閃
一閃的光茫，十分耀眼。

LONG);
	setup();
	replace_program(ROOM);
}
