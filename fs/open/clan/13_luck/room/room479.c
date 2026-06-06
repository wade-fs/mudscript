inherit ROOM;
void create() {
	set( "short", "萬利當鋪" );
	set( "object", ([
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/obj/sun-heart",
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
	]) );
	set( "owner", "zmud" );
	set( "build", 10002 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room480",
	]) );
	set( "long", @LONG

    這是一家中等規模的當鋪﹐老舊的櫃臺上放著一張木牌(sign)﹐屋
裡的光線不是很亮﹐往東的出口被一塊藍色布簾遮著﹐上面有「非請莫
入」的字樣﹐西邊有一扇木雕門通往大街﹐當鋪老板好像不在，不過櫃
檯後面有個年輕夥計﹐你還是可以買賣典當東西。

LONG);
	setup();
	replace_program(ROOM);
}
