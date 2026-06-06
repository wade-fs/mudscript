inherit ROOM;
void create() {
	set( "short", "天地水陣" );
	set( "object", ([
		"file6"    : "/open/magic-manor/obj/sun-heart",
		"file10"   : "/open/mogi/dragon/obj/dragon-head",
		"file7"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/obj/gift/xiandan",
		"amount7"  : 214,
		"file5"    : "/open/capital/obj/book",
		"file2"    : "/open/fire-hole/obj/y-pill",
		"amount10" : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"amount2"  : 111,
		"amount4"  : 366,
		"amount9"  : 1,
		"file9"    : "/open/mogi/dragon/obj/dragon-head",
		"file3"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/fire-hole/obj/r-pill",
	]) );
	set( "build", 10464 );
	set( "light_up", 1 );
	set( "owner", "soul" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room642",
		"south"     : "/open/clan/13_luck/room/room644",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是天地五行的『水』陣，上引九天之水，下通地
獄之火。此時你已全身泡在水中，用內力轉換成內呼吸
，吃力地繼續前進。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
