inherit ROOM;
void create() {
	set( "short", "Ddt-土靈塔一樓" );
	set( "object", ([
		"amount7"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10016 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room638",
		"out"       : "/open/clan/sky-wu-chi/room/room627",
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
