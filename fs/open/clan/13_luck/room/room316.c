inherit ROOM;
void create() {
	set( "short", "吉祥置物櫃辛" );
	set( "object", ([
		"amount9"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount8"  : 1,
	]) );
	set( "build", 10023 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room304",
	]) );
	set( "long", @LONG

    這裡是吉祥置物櫃辛，專門為還沒有房間的新進幫眾所設立的，此
環境優雅舒適，讓新進的幫眾有個可以去的地方跟休息的地方，使他們
快點成為十三吉祥的戰力，一起為幫派的未來而努力，一同打拼，長記
慈惠傳後世，永留點範在十三，希望能為天下第一大幫而邁進。

LONG);
	setup();
	replace_program(ROOM);
}
