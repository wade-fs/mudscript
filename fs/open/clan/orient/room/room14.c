inherit ROOM;
void create() {
	set( "short", "$HIG$丹藥之閣$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"amount10" : 1,
		"file9"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount3"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount6"  : 1,
		"file3"    : "/open/mogi/castle/obj/seven2-dark-head",
		"file8"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file10"   : "/open/mogi/castle/obj/seven2-dark-head",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount7"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file1"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file6"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file7"    : "/open/mogi/castle/obj/seven3-dark-head",
	]) );
	set( "build", 10188 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/orient/room/room13",
		"north"     : "/open/clan/orient/room/room15",
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
