inherit ROOM;
void create() {
	set( "short", "$HIW$『三樓長廊』$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room40",
		"west"      : "/open/clan/orient/room/room42",
		"up"        : "/open/clan/orient/room/room39",
		"north"     : "/open/clan/orient/room/room43",
		"down"      : "/open/clan/orient/room/room37",
		"south"     : "/open/clan/orient/room/room41",
	]) );
	set( "long", @LONG

    這是一條非常精美的長廊，柱子和欄桿是用華貴的紫檀木制成，上面
雕飾著美麗的圖畫，畫工精巧，美不勝收。長廊的兩邊放滿了盆栽。一陣
陣的涼風迎面吹來，微風輕拂花園裡的花草，一種悠然安詳的氣氛，讓然
忘卻塵世的煩憂，讓人充份感受到道家清靜無為的心境。走廊向四面延伸
出去，分別為龍郡主、風郡主、舞郡主、甜郡主的臥房。

LONG);
	setup();
	replace_program(ROOM);
}
