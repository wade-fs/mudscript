inherit ROOM;
void create() {
	set( "short", "$HIY$明日金行陣$NOR$" );
	set( "object", ([
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10106 );
	set( "owner", "tomorrow" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room738",
		"south"     : "/open/clan/13_luck/room/room736.c",
	]) );
	set( "long", @LONG

這裡是tomorrow所排設的五行陣之一  金行陣
一踏入此地  滿山滿谷的黃金  讓你目不暇給
心想這麼多黃金  一輩子就不愁吃不愁了
不禁把黃金堆滿身  結果反而被黃金壓垮  動彈不得
這裡是tomorrow所排設的五行陣之一  金行陣
一踏入此地  滿山滿谷的黃金  讓你目不暇給
心想這麼多黃金  一輩子就不愁吃不愁了
不禁把黃金堆滿身  結果反而被黃金壓垮  動彈不得
LONG);
	setup();
	replace_program(ROOM);
}
