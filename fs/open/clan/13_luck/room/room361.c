inherit ROOM;
void create() {
	set( "short", "藍龍丹房" );
	set( "object", ([
		"file2"    : "/open/fire-hole/obj/b-pill",
		"amount4"  : 100,
		"amount1"  : 100,
		"amount3"  : 100,
		"amount10" : 1,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount2"  : 100,
		"amount5"  : 100,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount6"  : 1,
		"file4"    : "/open/fire-hole/obj/b-pill",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10104 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room364",
		"west"      : "/open/clan/13_luck/room/room358.c",
		"north"     : "/open/clan/13_luck/room/room359.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在火龍幻界裡，有六種色龍分別是白光。紫光。紅光。藍光。黃
光。綠光火龍，每一隻火龍都是非常兇猛，沒有四到五個武術家合力
圍攻，想要打倒火龍簡直是癡心妄想，從它們的體內都可以找到稀有
的精元，不同顏色的精元有不同的功效，藍龍精元具有暫時增加內力
的功效。

LONG);
	setup();
	replace_program(ROOM);
}
