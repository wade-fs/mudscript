inherit ROOM;
void create() {
	set( "short", "Ddt-土靈塔七樓" );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room627",
	]) );
	set( "owner", "wendy" );
	set( "long", @LONG
漫天的塵沙，群集飛舞，滿地的泥濘，東奔西竄，有如一個活體
般的土靈塔，所聚的一沙一土，似具有靈性一樣，感應到了陌生的氣
息就朝那氣息捲去，所到之處泥濘不堪，生命的氣息也點滴消失。
這裡適靈塔的最後一層，往外一跳就可以回到聚靈到倉庫
LONG);
	setup();
	replace_program(ROOM);
}
