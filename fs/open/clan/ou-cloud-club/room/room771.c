inherit ROOM;
void create() {
	set( "short", "樹洞" );
	set( "owner", "snowy" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file8"    : "/obj/gift/xisuidan",
		"file6"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/xisuidan",
		"file10"   : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"file9"    : "/obj/gift/xisuidan",
		"file2"    : "/obj/gift/xisuidan",
		"file4"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"file7"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10765 );
	set( "exits", ([
		"enter"     : "/open/clan/ou-cloud-club/room/room43",
		"east"      : "/open/clan/ou-cloud-club/room/room769",
	]) );
	set( "long", @LONG
雖是一個樹洞，但是視野卻不像其他的樹洞那樣的漆黑，反而可以看得
很遠，遠方的森林似乎已經被濛濛的霧氣給籠罩住了，所以看不清楚遠方究
竟是何種景致，而看看樹洞的周圍，不是一些樹枝，就是一些藤蔓，不禁讓
人對這片森林感到厭煩。
LONG);
	setup();
	replace_program(ROOM);
}
