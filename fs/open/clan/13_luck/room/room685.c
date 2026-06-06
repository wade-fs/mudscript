inherit ROOM;
void create() {
	set( "short", "七彩陣之藍陣" );
	set( "object", ([
		"amount7"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"amount3"  : 799,
		"file6"    : "/obj/gift/shenliwan",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount8"  : 1,
		"file2"    : "/obj/gift/unknowdan",
		"file7"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"file5"    : "/obj/gift/shenliwan",
	]) );
	set( "build", 10055 );
	set( "owner", "zmud" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room686.c",
		"north"     : "/open/clan/13_luck/room/room684",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是七彩陣的『藍』陣，眼前所見的景物都是水藍
色的一片，看很來很舒服。陣中央有根『藍水晶』，正
是此陣的鎮陣之寶，也是七彩陣的第五根水晶。因此，
經過前幾陣的試煉，再困難也要將它拔出，繼續前進。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
