inherit ROOM;
void create() {
	set( "short", "龍之穴" );
	set( "owner", "pighead" );
	set( "object", ([
		"file8"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount7"  : 1,
		"amount9"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/hobowdan",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"file1"    : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/gblade/obj/dragon_book",
		"amount10" : 1,
	]) );
	set( "build", 10194 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room348",
		"out"       : "/open/clan/13_luck/room/room265.c",
		"south"     : "/open/clan/13_luck/room/room324.c",
	]) );
	set( "long", @LONG

    簡單的石床，幾張石椅石桌，上面幾本的武功書籍散亂放置，整
天沈浸於武學的究極境界。旁邊就放著一些主人所愛穿的衣服防具，
旁邊還有幾隻奇異的小動物在嘻戲玩耍著，長著小翅膀，不時飛旋於
空中，口中偶而還會吐著小小的火焰，會不會是武林中的傳言神獸─
聖獸‧燚


LONG);
	setup();
	replace_program(ROOM);
}
