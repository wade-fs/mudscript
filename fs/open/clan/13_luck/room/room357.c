inherit ROOM;
void create() {
	set( "short", "綠龍丹房" );
	set( "object", ([
		"file5"    : "/open/fire-hole/obj/g-pill",
		"amount9"  : 500,
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount3"  : 500,
		"amount5"  : 500,
		"amount6"  : 500,
		"file10"   : "/open/fire-hole/obj/g-pill",
		"amount2"  : 500,
		"file7"    : "/open/fire-hole/obj/g-pill",
		"amount7"  : 500,
		"file6"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 500,
		"amount1"  : 500,
		"file4"    : "/open/fire-hole/obj/g-pill",
		"amount10" : 500,
		"file9"    : "/open/fire-hole/obj/g-pill",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 500,
	]) );
	set( "build", 10113 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room360",
		"south"     : "/open/clan/13_luck/room/room144.c",
	]) );
	set( "long", @LONG

    在火龍幻界裡，有六種色龍分別是白光。紫光。紅光。藍光。黃
光。綠光火龍，每一隻火龍都是非常兇猛，沒有四到五個武術家合力
圍攻，想要打倒火龍簡直是癡心妄想，從它們的體內都可以找到稀有
的精元，不同顏色的精元有不同的功效，綠龍精元具有暫時增加刀法
的功效。

LONG);
	setup();
	replace_program(ROOM);
}
