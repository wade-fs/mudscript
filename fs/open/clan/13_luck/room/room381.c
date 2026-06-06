inherit ROOM;
void create() {
	set( "short", "演武房" );
	set( "object", ([
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/obj/gift/unknowdan",
		"file8"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"amount9"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"file7"    : "/obj/gift/xiandan",
		"amount2"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room383",
	]) );
	set( "long", @LONG

    演武房的兩旁擺設著一排排的書櫃，書櫃之中所放的書都是中國歷朝
名將所寫的兵書，而房內正中央的檀木大桌正是讓戰堂弟子們研究書中兵
法的模擬戰場。而創立古皇朝的巨龍愁，便是由這領悟到在戰爭中所求的
並不是個人的武術，而是講求團體合作的道理。

LONG);
	setup();
	replace_program(ROOM);
}
