inherit ROOM;
void create() {
	set( "short", "七彩陣之綠陣" );
	set( "object", ([
		"amount8"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/obj/gift/unknowdan",
		"file6"    : "/open/ghost-hole/obj/fire-spirit",
		"file9"    : "/open/ghost-hole/obj/light-spirit",
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"amount10" : 1,
		"amount3"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"file3"    : "/open/ghost-hole/obj/wind-spirit",
		"amount1"  : 1,
		"amount2"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file8"    : "/obj/gift/unknowdan",
	]) );
	set( "build", 10561 );
	set( "owner", "zmud" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room687.c",
		"north"     : "/open/clan/13_luck/room/room685",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是七彩陣的『綠』陣，眼前所見的景物都是綠油
油的一片。陣中央有根『綠水晶』，正是要通過此陣的
鑰匙，也是七彩陣的第四根水晶。你已經在七彩陣的中
央，無法回頭了，只能繼續前進。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
