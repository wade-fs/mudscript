inherit ROOM;
void create() {
	set( "short", "$HIR$兵器之間$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"amount7"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10077 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/orient/room/room7.c",
		"north"     : "/open/clan/orient/room/room9",
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
