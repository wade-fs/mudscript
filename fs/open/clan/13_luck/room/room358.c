inherit ROOM;
void create() {
	set( "short", "紅龍丹房" );
	set( "object", ([
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 400,
		"amount2"  : 400,
		"amount9"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"amount1"  : 600,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount10" : 1,
	]) );
	set( "build", 10083 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room361",
		"north"     : "/open/clan/13_luck/room/room144.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在火龍幻界裡，有六種色龍分別是白光。紫光。紅光。藍光。黃
光。綠光火龍，每一隻火龍都是非常兇猛，沒有四到五個武術家合力
圍攻，想要打倒火龍簡直是癡心妄想，從它們的體內都可以找到稀有
的精元，不同顏色的精元有不同的功效，紅龍精元具有暫時增加閃躲
的功效。

LONG);
	setup();
	replace_program(ROOM);
}
