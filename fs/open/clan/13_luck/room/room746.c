inherit ROOM;
void create() {
	set( "short", "LEON丹藥房" );
	set( "object", ([
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount5"  : 2,
		"file10"   : "/open/gblade/obj/sa-head",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"file3"    : "/open/mon/obj/mon-pill",
		"file4"    : "/open/killer/obj/atman_pill",
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount4"  : 1150,
		"amount3"  : 387,
		"amount1"  : 59,
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 309,
		"file1"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10002 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room745",
	]) );
	set( "long", @LONG
逍遙派聖藥,具有神奇無比的療效,幾可起死回生 一種黃色外
觀卻有著無比神奇的力量 這就是武林中人最渴望得到的傳說
中神藥之一 可惜在此滿地都是 讓人不禁對這些丹藥的真假 
感到懷疑 最後你還是克制不了密藥的誘惑 偷偷拿了一把帶
了出去 希望不會被別人發現 否則再多替身都不夠用 所以希
望千萬不要被發現

LONG);
	setup();
	replace_program(ROOM);
}
