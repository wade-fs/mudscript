inherit ROOM;
void create() {
	set( "short", "醉仙亭" );
	set( "owner", "papt" );
	set( "object", ([
		"amount4"  : 1,
		"file10"   : "/obj/poison/dark_poison",
		"file9"    : "/open/main/obj/et_sword",
		"amount6"  : 429,
		"amount2"  : 1,
		"file1"    : "/open/doctor/obj/feather",
		"amount1"  : 1,
		"amount8"  : 812,
		"amount9"  : 1,
		"amount7"  : 682,
		"file4"    : "/open/doctor/obj/feather",
		"amount5"  : 235,
		"amount10" : 100,
		"file3"    : "/open/doctor/obj/d-mark",
		"file6"    : "/obj/poison/rose_poison",
		"file8"    : "/obj/poison/dark_poison",
		"file7"    : "/obj/poison/five_poison",
		"file5"    : "/obj/poison/rose_poison",
		"amount3"  : 1,
		"file2"    : "/open/doctor/obj/feather",
	]) );
	set( "build", 11094 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room62",
	]) );
	set( "long", @LONG

    來到這裡，四周種滿無數奇花異卉，一座由青龍盤天，玄武守護
的五角涼亭置立於此，仔細一看，亭中圓桌於中，白虎形狀的無數石
倚隨意置於亭內，石質皆由大理陶瓷鑄造而成，四大石柱上分別刻上
朱雀騰空之飛舞美姿，亭旁小河孱孱，游魚細數，岸邊草木相映，鶴
立其中，四周景觀如畫，令你不禁想坐在亭中細觀這無數美景。

LONG);
	setup();
	replace_program(ROOM);
}
