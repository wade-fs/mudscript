inherit ROOM;
void create() {
	set( "short", "龍蜒神弓室" );
	set( "object", ([
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10920 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room274",
	]) );
	set( "long", @LONG

    名震江湖神射手李廣，手持龍蜒神弓敗盡天下英雄，與他作戰就跟
死神打交道一般，除了一身射功之後，成名招式十萬火擊更是暴力，萬
箭齊發夠是沒醫生在就準備受死了，所以跟他為敵也是要速戰速決，必
免長久，否則攻擊不準傷害減半就吃不完兜著走。

LONG);
	setup();
	replace_program(ROOM);
}
