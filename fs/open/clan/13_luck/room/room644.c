inherit ROOM;
void create() {
	set( "short", "天地木陣" );
	set( "object", ([
		"file1"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/obj/lunar-heart",
		"file2"    : "/open/magic-manor/obj/lunar-heart",
		"file3"    : "/open/magic-manor/obj/sun-heart",
		"file7"    : "/open/magic-manor/obj/lunar-heart",
		"file10"   : "/obj/gift/xisuidan",
		"amount10" : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/obj/lunar-heart",
		"file5"    : "/open/magic-manor/obj/sun-heart",
		"file9"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/obj/sun-heart",
		"amount9"  : 257,
		"amount2"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10232 );
	set( "light_up", 1 );
	set( "owner", "soul" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room643",
		"south"     : "/open/clan/13_luck/room/room645",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是天地五行的『木』陣，上引九天之氣，下通地
獄之火。四處樹木林立，時而化作木妖攻擊你，使你不
得不集中精神，戒備繼續前進。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
