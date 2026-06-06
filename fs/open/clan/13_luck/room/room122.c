inherit ROOM;
void create() {
	set( "short", "《 雨 倩 竹 》" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/snow/obj/figring",
		"file9"    : "/obj/stone/powder",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount7"  : 8,
		"amount9"  : 8,
		"amount8"  : 1,
		"file2"    : "/open/capital/obj/chen_dagger",
		"file6"    : "/open/poison/obj/pearl",
		"file8"    : "/obj/stone/suipian",
		"file3"    : "/open/mogi/castle/obj/blood-water",
	]) );
	set( "owner", "dunga" );
	set( "item_desc", ([
		"test" : @ITEM
這是測試
ITEM,
	]) );
	set( "build", 10131 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room98",
		"enter"     : "/open/clan/13_luck/room/room121",
	]) );
	set( "long", @LONG

┌────┐
│ 憶  廬 │     《 雨 倩 竹 》
├───┤│   竹築同音，此《雨倩竹築》乃石之軒
│        │與其妻雨倩雙棲之所。石之軒身集近百年
│ 思 定  │魔功大成，除了比金鐘罩更強的天魔金身外
│        │壯年更創出武林聞名喪膽的惡化魔功(badforce)
│├───┤
│  前廳  │        混元混殺擊
│        │
└─┤├─┘自此江湖人稱邪王
    大門

此築結構分三徑，由大門進來分別為前廳、思定、憶廬
然後後面就是邪王和其妻的閨房了
LONG);
	setup();
	replace_program(ROOM);
}
