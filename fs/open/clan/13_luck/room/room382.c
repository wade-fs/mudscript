inherit ROOM;
void create() {
	set( "short", "習武房" );
	set( "object", ([
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"amount3"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10080 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room383",
	]) );
	set( "long", @LONG

    這裡是十三戰堂弟子們練習其平時從戰十三那所學武術的地方，希望
藉彼此之間平時所學的來彼此激勵，進而悟出自己的一套武術，而當初四
強武者中的巨龍愁之所以會成功，亦是靠師兄弟們的互相幫忙，加上其原
本的天賦，而在大校場中擊敗自己的師父戰十三。

LONG);
	setup();
	replace_program(ROOM);
}
