inherit ROOM;
void create() {
	set( "short", "$HIG$丹藥之閣$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"amount6"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/mogi/castle/obj/black-ghost-head",
		"amount7"  : 1,
		"file5"    : "/open/mogi/castle/obj/white-ghost-head",
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"file9"    : "/open/mogi/castle/obj/black-ghost-head",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/mogi/castle/obj/white-ghost-head",
	]) );
	set( "build", 10007 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/orient/room/room14.c",
	]) );
	set( "long", @LONG
這是一條非常精美的長廊，柱子和欄桿是用華貴的紫檀木制成，上面
雕飾著美麗的圖畫，畫工精巧，美不勝收。長廊的兩邊放滿了盆栽。一陣
陣的涼風迎面吹來，微風輕拂花園裡的花草，一種悠然安詳的氣氛，讓然
忘卻塵世的煩憂，讓人充份感受到道家清靜無為的心境。
LONG);
	setup();
	replace_program(ROOM);
}
