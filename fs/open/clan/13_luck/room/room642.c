inherit ROOM;
void create() {
	set( "short", "天地火陣" );
	set( "object", ([
		"file10"   : "/open/mogi/dragon/obj/dragon-head",
		"amount3"  : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"file8"    : "/open/mogi/dragon/obj/dragon-head",
		"file3"    : "/open/magic-manor/obj/lunar-heart",
		"file6"    : "/open/ping/obj/poison_pill",
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
		"amount6"  : 110,
		"amount4"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
	]) );
	set( "build", 10048 );
	set( "light_up", 1 );
	set( "owner", "soul" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room641",
		"south"     : "/open/clan/13_luck/room/room643",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是天地五行的『火』陣，上引九天之氣，下通地
獄之火。烈火熊熊，燒得你快脫水了，皮膚傳來陣陣燒
焦味，但你仍勇敢地繼續前進。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
