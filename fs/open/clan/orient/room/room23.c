inherit ROOM;
void create() {
	set( "short", "$CYN$水之倉庫$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"amount10" : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/killer/memory/static",
		"amount9"  : 1,
		"file9"    : "/open/killer/memory/static",
		"file4"    : "/open/killer/memory/static",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/killer/memory/static",
		"file1"    : "/open/killer/memory/static",
		"file5"    : "/open/killer/memory/static",
		"file7"    : "/open/killer/memory/static",
		"file10"   : "/open/killer/memory/static",
		"amount6"  : 1,
		"file2"    : "/open/killer/memory/static",
		"file8"    : "/open/killer/memory/static",
		"amount8"  : 1,
	]) );
	set( "build", 10187 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/orient/room/room22.c",
		"north"     : "/open/clan/orient/room/room24.c",
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
