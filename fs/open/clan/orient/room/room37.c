inherit ROOM;
void create() {
	set( "short", "$HIW$『二樓長廊』$NOR$" );
	set( "build", 21 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room26.c",
		"up"        : "/open/clan/orient/room/room38.c",
		"down"      : "/open/clan/orient/room/hall.c",
		"west"      : "/open/clan/orient/room/room54.c",
	]) );
	set( "long", @LONG

    這是一條非常精美的長廊，柱子和欄桿是用華貴的紫檀木制成，上面
雕飾著美麗的圖畫，畫工精巧，美不勝收。長廊的兩邊放滿了盆栽。一陣
陣的涼風迎面吹來，微風輕拂花園裡的花草，一種悠然安詳的氣氛，讓然
忘卻塵世的煩憂，讓人充份感受到道家清靜無為的心境。走廊向東西延伸
出去，往東通往湘王室，西邊則是陵王室。

LONG);
	setup();
	replace_program(ROOM);
}
