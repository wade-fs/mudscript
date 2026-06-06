inherit ROOM;
void create() {
	set( "short", "$HIG$丹藥之閣$NOR$" );
	set( "owner", "working" );
	set( "build", 10150 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/orient/room/room11.c",
		"north"     : "/open/clan/orient/room/room13",
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
