inherit ROOM;
void create() {
	set( "short", "$HIG$明日木行陣$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"amount8"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10499 );
	set( "owner", "tomorrow" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room739",
		"south"     : "/open/clan/13_luck/room/room737",
	]) );
	set( "long", @LONG
這裡是tomorrow所排設的五行陣之一  木行陣
茂密的大樹包圍著你  就像進到了雨林
四周傳來各種動物的叫聲  彷彿引領著你進到森林的深處
走著走著  已然迷失了方向  再也無法離開這裡 
這裡是tomorrow所排設的五行陣之一  木行陣
茂密的大樹包圍著你  就像進到了雨林
四周傳來各種動物的叫聲  彷彿引領著你進到森林的深處
走著走著  已然迷失了方向  再也無法離開這裡

LONG);
	setup();
	replace_program(ROOM);
}
