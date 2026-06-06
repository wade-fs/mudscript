inherit ROOM;
void create() {
	set( "short", "『洛陽客棧二樓』" );
	set( "owner", "mill" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_leg",
		"amount7"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_neck",
		"amount4"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/gsword/obj/yuskirt",
		"file5"    : "/open/gsword/obj/may_ring",
		"amount2"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_neck",
		"amount6"  : 1,
		"file7"    : "/open/gsword/obj/yau_glove",
		"file2"    : "/open/firedancer/npc/eq/r_pants",
		"amount3"  : 1,
	]) );
	set( "build", 10283 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room463",
		"south"     : "/open/clan/13_luck/room/room466",
	]) );
	set( "long", @LONG

     你現在來到了洛陽客棧的二樓﹐這家客棧跟明天客棧一樣有個很奇怪的
 規矩﹐就是只留宿名頭夠大的客人﹐如果你只是一個無名小卒﹐不論出再多
 銀兩都租不到一間空房﹐牆邊有一道樓梯通往三樓的茶座。不論出再多銀兩
 都租不到一間空房﹐牆邊有一道樓梯通往三樓的茶座。

LONG);
	setup();
	replace_program(ROOM);
}
