inherit ROOM;
void create() {
	set( "short", "紫龍丹房" );
	set( "object", ([
		"amount8"  : 1,
		"amount9"  : 1,
		"amount1"  : 300,
		"file2"    : "/open/fire-hole/obj/p-pill",
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 300,
		"amount2"  : 300,
		"file3"    : "/open/fire-hole/obj/p-pill",
		"file10"   : "/open/fire-hole/obj/p-pill",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 100,
	]) );
	set( "build", 10848 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room360",
		"south"     : "/open/clan/13_luck/room/room362.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在火龍幻界裡，有六種色龍分別是白光。紫光。紅光。藍光。黃
光。綠光火龍，每一隻火龍都是非常兇猛，沒有四到五個武術家合力
圍攻，想要打倒火龍簡直是癡心妄想，從它們的體內都可以找到稀有
的精元，不同顏色的精元有不同的功效，紫龍精元具有暫時增加靈咒
的功效。

LONG);
	setup();
	replace_program(ROOM);
}
