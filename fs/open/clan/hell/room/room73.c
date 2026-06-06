inherit ROOM;
void create() {
	set( "short", "$HIR$紅龍$NOR$區" );
	set( "object", ([
		"amount6"  : 100,
		"amount2"  : 100,
		"amount5"  : 100,
		"amount1"  : 100,
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 100,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file5"    : "/open/fire-hole/obj/r-pill",
	]) );
	set( "owner", "blur" );
	set( "build", 11508 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room27",
	]) );
	set( "long", @LONG

相信大家都看過內衣教父....
裡頭大飛最崇拜的人物就是生倉組的小林..
他神乎其技的閃躲功夫堪稱武林之冠...
其實....
他的躲功其來有自...
完全是靠紅龍精元所賜...
你可能又有疑問 : 為何紅龍精元能有如此神效??
唸過生物學的人就知道了...這完全是食物鏈導致..
因為..紅龍吃小強...而小強本生就具有天生無敵閃躲逃脫能力...
所以我們吃了紅龍精元後...必能腳底抹油...
像風依樣的溜來溜去...
如此邪惡的怪物就頂多只能摸到我們的屁股毛囉..wahaha!!

LONG);
	setup();
	replace_program(ROOM);
}
