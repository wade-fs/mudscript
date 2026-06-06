inherit ROOM;
void create() {
	set( "short", "飄雪閣" );
	set( "object", ([
		"amount9"  : 1,
		"file4"    : "/open/capital/obj/4-2",
		"file1"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount4"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/capital/obj/4-2",
		"file8"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount1"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10038 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room377",
	]) );
	set( "long", @LONG

    飄雪閣是劍十三懷念其恩師天道劍邪的地方，當劍十三還小的時候，
其父母避難天山，但依然被仇家找上，父母均死於仇家之手。當時他拼命
的逃，認為只要活著就有機會可以復仇雪恨。但天不從人願，仇家已追到
他且正準備殺他滅口，就在這瞬間一道寒冷的劍芒在仇家的頸部留下一道
血痕。他回頭一望只見大雪之中站著一人，而此人就是其恩師天道劍邪。
劍邪將其帶回十三吉祥並傳授其劍法，使他在十三吉祥內成為用劍的第二
人。劍邪走時便將堂主之位傳給他，希望他將劍法傳於堂內弟子。

LONG);
	setup();
	replace_program(ROOM);
}
