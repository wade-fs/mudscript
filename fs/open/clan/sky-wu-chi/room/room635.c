inherit ROOM;
void create() {
	set( "short", "漫天的塵沙，群集飛舞，滿地的泥濘，東奔西竄，有如一個活體" );
	set( "owner", "wendy" );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room634",
	]) );
	set( "long", @LONG
漫天的塵沙，群集飛舞，滿地的泥濘，東奔西竄，有如一個活體
般的土靈塔，所聚的一沙一土，似具有靈性一樣，感應到了陌生的氣
息就朝那氣息捲去，所到之處泥濘不堪，生命的氣息也點滴消失。
一個極其簡單的直立式樓梯，歷經常年的歲月洗禮，已變的破舊
不堪，可以通往靈塔下一樓。
LONG);
	setup();
	replace_program(ROOM);
}
