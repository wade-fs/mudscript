inherit ROOM;
void create() {
	set( "short", "$HIY$麟之倉庫$NOR$" );
	set( "owner", "working" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/seven1-dark-head",
		"file6"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount10" : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file5"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount8"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount1"  : 1,
		"file8"    : "/open/mogi/castle/obj/seven4-dark-head",
		"amount7"  : 1,
	]) );
	set( "build", 10247 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/orient/room/room18.c",
		"south"     : "/open/clan/orient/room/room16",
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
