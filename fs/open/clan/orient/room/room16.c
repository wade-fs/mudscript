inherit ROOM;
void create() {
	set( "short", "$HIC$陵王長廊$NOR$" );
	set( "owner", "working" );
	set( "object", ([
		"file6"    : "/open/mogi/castle/obj/seven5-dark-head",
		"file2"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount6"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file3"    : "/open/mogi/castle/obj/seven3-dark-head",
		"file5"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven5-dark-head",
		"file9"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file10"   : "/open/mogi/castle/obj/seven3-dark-head",
		"file4"    : "/open/mogi/castle/obj/seven4-dark-head",
		"amount3"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file8"    : "/open/mogi/castle/obj/seven6-dark-head",
	]) );
	set( "build", 10126 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room21",
		"east"      : "/open/clan/orient/room/room11.c",
		"north"     : "/open/clan/orient/room/room17.c",
	]) );
	set( "long", @LONG
這是一條非常精美的長廊，柱子和欄桿是用華貴的紫檀木制成，上面
雕飾著美麗的圖畫，畫工精巧，美不勝收。長廊的兩邊放滿了盆栽。一陣
陣的涼風迎面吹來，微風輕拂花園裡的花草，一種悠然安詳的氣氛，讓然
忘卻塵世的煩憂，讓人充份感受到道家清靜無為的心境。走廊向東西延伸
出去。
LONG);
	setup();
	replace_program(ROOM);
}
