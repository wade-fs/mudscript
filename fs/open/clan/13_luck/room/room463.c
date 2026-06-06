inherit ROOM;
void create() {
	set( "short", "『洛陽客棧三樓』" );
	set( "owner", "mill" );
	set( "object", ([
		"amount8"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_head",
		"file7"    : "/open/firedancer/npc/eq/r_belt",
		"file3"    : "/open/firedancer/npc/eq/r_finger",
		"file10"   : "/open/firedancer/npc/eq/r_pants",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_cloth",
		"file5"    : "/open/firedancer/npc/eq/r_cape",
		"file8"    : "/open/firedancer/npc/eq/r_armbands",
		"amount10" : 1,
		"file2"    : "/open/firedancer/npc/eq/r_hands",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_shield",
	]) );
	set( "build", 10068 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room464",
	]) );
	set( "long", @LONG

     你現在來到了洛陽客棧的三樓﹐由西邊的窗口可看到關帝廟前的廣場
 ，由東邊的窗口往下方看似乎有一道人影穿過(window), 牆邊有一道樓梯
 通往二樓。你現在來到了洛陽客棧的三樓﹐由西邊的窗口可看到關帝廟前
 的廣場，由東邊的窗口往下方看似乎有一道人影穿過(window), 牆邊有一
 道樓梯通往二樓。

LONG);
	setup();
	replace_program(ROOM);
}
