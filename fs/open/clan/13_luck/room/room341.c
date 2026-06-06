inherit ROOM;
void create() {
	set( "short", "七彩陣之紅陣" );
	set( "object", ([
		"amount7"  : 330,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"amount10" : 736,
		"amount2"  : 38,
		"file2"    : "/obj/stone/jiao",
		"file7"    : "/open/fire-hole/obj/y-pill",
		"amount4"  : 550,
		"file9"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 645,
		"file3"    : "/obj/stone/suipian",
		"file1"    : "/obj/stone/powder",
		"file8"    : "/open/fire-hole/obj/k-pill",
		"amount8"  : 287,
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount9"  : 660,
		"amount3"  : 172,
		"file6"    : "/open/mon/obj/mon-pill",
		"amount1"  : 481,
		"amount5"  : 313,
		"file10"   : "/open/ping/obj/poison_pill",
	]) );
	set( "owner", "zmud" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room286.c",
		"north"     : "/open/clan/13_luck/room/room688",
	]) );
	set( "build", 10812 );
	set( "light_up", 1 );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
     這是七彩陣的『紅』陣，眼前所見的景物都是火紅
一片，彷彿回到單色的世界。陣中央有根『紅水晶』，
正是破此陣的必要之物。因此，你必須步步為營，，鎮
攝自己不安的心，拔出水晶，才能繼續前進。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
