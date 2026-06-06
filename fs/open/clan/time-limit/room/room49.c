inherit ROOM;
void create() {
	set( "short", "$HIM$寵物$HIC$商店$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10804 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room52",
	]) );
	set( "long", @LONG
巫師世界也流行養寵物,一般都是貓和老鼠,而蟾蜍在前幾年就已經退流行了,
所以店裡有著多數的貓和老鼠,蟾蜍卻沒幾隻,有些寵物具有高度的危險性,
而被魔法部下令禁止飼養,店裡都是合法的寵物,非法的寵物則無法在這裡買到,
海格曾經養過一隻龍當寵物,結果差點把房子給燒掉,所以養寵物得要慎選才行

LONG);
	setup();
	replace_program(ROOM);
}
