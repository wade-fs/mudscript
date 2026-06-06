inherit ROOM;
void create() {
	set( "short", "皇城大道" );
	set( "object", ([
		"file9"    : "/open/magic-manor/obj/hwa-je-icer",
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 8,
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"amount8"  : 1,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount2"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/mogi/dragon/obj/power",
	]) );
	set( "build", 10042 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room6",
		"west"      : "/open/clan/13_luck/room/room431",
		"pass"      : "/open/clan/13_luck/room/room726",
		"east"      : "/open/clan/13_luck/room/room434.c",
		"south"     : "/open/clan/13_luck/room/room4.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是十三吉祥的大本營--皇城，放眼望去盡是深宮穹樓，一股莊
嚴的氣氛籠罩著整個皇城，使你望之卻步，腳下石版上刻著面龍騰鳳舞
之浮雕，乃十三吉祥花費無數人力所鑿造而成，非幫中之人，一但踏入
皇城之中再難回頭, 只有落的喪生殘體之下場...

LONG);
	setup();
	replace_program(ROOM);
}
