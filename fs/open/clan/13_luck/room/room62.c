inherit ROOM;
void create() {
	set( "short", "相思林" );
	set( "owner", "papt" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room65.c",
		"east"      : "/open/clan/13_luck/room/room63.c",
		"out"       : "/open/clan/13_luck/room/room61",
		"down"      : "/open/clan/13_luck/room/room116",
		"north"     : "/open/clan/13_luck/room/room64",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
殺意魔戒是相傳產於天山派禁地的礦石所煉出的魔水晶所製成,平時是黑牙聯的殺手
賴以成名的殺敵利器,一般人想要得到除了挑戰黑牙聯主席外別無他法,還要冒著被追殺
的危險,小敏幫主特地任命幫中的殺手收集一些戒指,收藏在這裡以為備用
LONG);
	setup();
	replace_program(ROOM);
}
