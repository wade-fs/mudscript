inherit ROOM;
void create() {
	set( "short", "黃龍丹房" );
	set( "object", ([
		"amount4"  : 50,
		"amount1"  : 300,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/fire-hole/obj/y-pill",
		"file2"    : "/open/fire-hole/obj/y-pill",
		"file1"    : "/open/fire-hole/obj/y-pill",
		"amount2"  : 300,
		"amount3"  : 300,
		"file3"    : "/open/fire-hole/obj/y-pill",
	]) );
	set( "build", 10245 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room363",
		"west"      : "/open/clan/13_luck/room/room357.c",
		"south"     : "/open/clan/13_luck/room/room359.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在火龍幻界裡，有六種色龍分別是白光。紫光。紅光。藍光。黃
光。綠光火龍，每一隻火龍都是非常兇猛，沒有四到五個武術家合力
圍攻，想要打倒火龍簡直是癡心妄想，從它們的體內都可以找到稀有
的精元，不同顏色的精元有不同的功效，黃龍精元具有暫時增加劍法
的功效。

LONG);
	setup();
	replace_program(ROOM);
}
