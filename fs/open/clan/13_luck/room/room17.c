inherit ROOM;
void create() {
	set( "short", "白虎堂" );
	set( "owner", "mad" );
	set( "build", 211 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room12",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    一進白虎堂看到一面刻有猛虎的圖案，你被嚇了一跳，其實這也是
十三吉祥審理案件的地方，只要犯罪的人一進到這裡都會被這隻猛虎嚇
到腿軟使案件更好審理，聽說這隻猛虎有時晚上會巡視十三吉祥，有不
少人說有看過。

LONG);
	setup();
	replace_program(ROOM);
}
