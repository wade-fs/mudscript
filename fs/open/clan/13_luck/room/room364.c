inherit ROOM;
void create() {
	set( "short", "白龍丹房" );
	set( "object", ([
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount8"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount3"  : 200,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 200,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10632 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room361",
		"north"     : "/open/clan/13_luck/room/room362.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在火龍幻界裡，有六種色龍分別是白光。紫光。紅光。藍光。黃
光。綠光火龍，每一隻火龍都是非常兇猛，沒有四到五個武術家合力
圍攻，想要打倒火龍簡直是癡心妄想，從它們的體內都可以找到稀有
的精元，不同顏色的精元有不同的功效，白龍精元具有暫時增加硬甲
的功效。

LONG);
	setup();
	replace_program(ROOM);
}
