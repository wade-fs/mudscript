inherit ROOM;
void create() {
	set( "short", "七彩陣之靛陣" );
	set( "object", ([
		"file2"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"amount8"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file4"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"file10"   : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"file9"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"amount3"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
	]) );
	set( "build", 10026 );
	set( "owner", "zmud" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room685",
		"north"     : "/open/clan/13_luck/room/room683",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是七彩陣的『靛』陣，眼前所見的景物都是靛青
色，死氣沉沉的樣子。陣中央有根『靛水晶』，正是破
此陣的必要之物，也是七彩陣的第六根水晶。因此，拔
出水晶，才能前進，別無它法。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
