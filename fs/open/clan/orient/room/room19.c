inherit ROOM;
void create() {
	set( "short", "$HIY$麟之倉庫$NOR$" );
	set( "object", ([
		"file7"    : "/open/mogi/castle/obj/white-ghost-head",
		"file10"   : "/open/mogi/castle/obj/black-ghost-head",
		"file8"    : "/open/mogi/castle/obj/black-ghost-head",
		"file5"    : "/open/mogi/castle/obj/white-ghost-head",
		"amount7"  : 1,
		"file2"    : "/open/mogi/castle/obj/black-ghost-head",
		"amount5"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"file1"    : "/open/mogi/castle/obj/white-ghost-head",
		"amount2"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/mogi/castle/obj/white-ghost-head",
		"file3"    : "/open/mogi/castle/obj/white-ghost-head",
		"amount1"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/mogi/castle/obj/black-ghost-head",
	]) );
	set( "owner", "spicy" );
	set( "build", 10103 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/orient/room/room18",
		"north"     : "/open/clan/orient/room/room20",
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
