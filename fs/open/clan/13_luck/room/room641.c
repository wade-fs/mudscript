inherit ROOM;
void create() {
	set( "short", "天地土陣" );
	set( "owner", "soul" );
	set( "object", ([
		"file8"    : "/open/mogi/dragon/obj/dragon-head",
		"file9"    : "/open/mogi/dragon/obj/dragon-head",
		"amount7"  : 1,
		"file6"    : "/open/ghost-hole/obj/light-spirit",
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
		"amount6"  : 1,
		"amount10" : 1,
		"file1"    : "/open/mogi/dragon/obj/dragon-head",
		"amount8"  : 1,
		"amount5"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
		"file2"    : "/obj/gift/unknowdan",
		"file7"    : "/open/mogi/dragon/obj/dragon-head",
		"amount2"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/magic-manor/obj/lunar-heart",
		"amount3"  : 1,
	]) );
	set( "build", 10285 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room640",
		"south"     : "/open/clan/13_luck/room/room642",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是天地五行的『土』陣，上引九天之氣，下通地
獄之火。四處都是一片荒蕪，了無生氣，難道這就是人
間煉域？還是快步前進吧！
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
