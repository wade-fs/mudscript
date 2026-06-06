inherit ROOM;
void create() {
	set( "short", "七彩陣之黃陣" );
	set( "object", ([
		"amount6"  : 615,
		"file10"   : "/open/firedancer/npc/eq/r_finger",
		"amount10" : 1,
		"amount7"  : 137,
		"amount9"  : 15,
		"file3"    : "/open/firedancer/npc/eq/r_hands",
		"amount5"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/fire-hole/obj/y-pill",
		"file1"    : "/obj/gift/hobowdan",
		"file2"    : "/open/firedancer/npc/eq/r_pants",
		"file8"    : "/open/firedancer/npc/eq/r_boots",
		"file6"    : "/open/ping/obj/poison_pill",
		"amount1"  : 1,
		"amount4"  : 13,
		"amount2"  : 1,
		"file5"    : "/obj/gift/xiandan",
		"file9"    : "/open/mon/obj/mon_item",
		"file7"    : "/open/mon/obj/mon-pill",
		"amount8"  : 1,
	]) );
	set( "build", 10042 );
	set( "owner", "zmud" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room688.c",
		"north"     : "/open/clan/13_luck/room/room686",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是七彩陣的『黃』陣，眼前所見的景物都是黃色
，彷彿就是單色的世界。陣中央有根『黃水晶』，正是
破此陣的寶物，也是七彩陣的第三根水晶。除了拿到水
晶，否則無法繼續前進。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
