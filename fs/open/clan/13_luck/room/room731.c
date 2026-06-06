inherit ROOM;
void create() {
	set( "short", "包好吃" );
	set( "object", ([
		"file1"    : "/obj/stone/jiao",
		"file3"    : "/open/ghost-hole/obj/light-spirit",
		"file2"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount3"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount1"  : 2,
		"amount6"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
		"file8"    : "/obj/gift/xisuidan",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
	]) );
	set( "owner", "hyun" );
	set( "build", 10040 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room670",
	]) );
	set( "long", @LONG

      包好吃  , 一家在金山街快速竄紅的餐館, 亮麗的招牌高掛在上,
但門面卻顯得不太撘, 怎麼會有油漆在門窗上呢? 原來是因為生意太好遭
同業報復才被潑的, 由此可見可能真的很好吃吧一走進裡頭, 寬敞的用餐
空間, 讓人覺得心曠神怡, 找個位子坐了下來, 點個牛肉麵, 好好享受一
頓美食吧!


LONG);
	setup();
	replace_program(ROOM);
}
