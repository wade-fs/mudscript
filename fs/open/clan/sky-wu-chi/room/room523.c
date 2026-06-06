inherit ROOM;
void create() {
	set( "short", "殺神齋裡間" );
	set( "owner", "piccolo" );
	set( "object", ([
		"amount5"  : 6,
		"amount9"  : 2,
		"file5"    : "/obj/stone/powder",
		"file2"    : "/open/capital/obj/blade2",
		"file6"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount1"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/wu/obj/ya-head",
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"amount4"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/power",
		"file9"    : "/obj/stone/suipian",
		"amount3"  : 1,
		"amount8"  : 4,
		"file4"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "build", 10222 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room479",
	]) );
	set( "long", @LONG
這個小房間非常樸素，樸素到什麼東西都沒有，
你仔細的搜索了一遍，發現還是沒東西...
想想還是出去好了，真沒想到這裏的主人這麼窮！
不過為了表示你是個大方的人，還是放幾顆鑽石給他好了...
這樣下次再來也許就可以發現這裡藏有很多寶物了！
LONG);
	setup();
	replace_program(ROOM);
}
