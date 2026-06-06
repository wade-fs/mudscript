inherit ROOM;
void create() {
	set( "short", "炎龍谷" );
	set( "object", ([
		"file1"    : "/open/ghost-hole/obj/living-water",
		"amount4"  : 19,
		"amount1"  : 1,
		"file9"    : "/u/p/pana/q/obj/hung-head",
		"amount2"  : 38,
		"file7"    : "/open/capital/obj/blade2",
		"amount10" : 1,
		"amount5"  : 3,
		"amount3"  : 20,
		"file10"   : "/open/killer/memory/static",
		"amount7"  : 1,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/open/magic-manor/obj/magic-sign",
		"file3"    : "/open/fire-hole/obj/y-pill",
		"file5"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 1,
		"file4"    : "/open/fire-hole/obj/b-pill",
		"amount9"  : 1,
	]) );
	set( "build", 10757 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room179",
		"enter"     : "/open/clan/13_luck/room/room490",
	]) );
	set( "long", @LONG

    這裡是傳說中的炎龍谷，一進入谷中發現幾隻可愛的小動物在嘻
戲玩耍著，長著小翅膀，不時飛旋於空中，讓你想要把它們抱起來把
玩，就在你抱起它的同時，遠處傳來具大的腳步聲，讓你覺得心生畏
懼，難到真的有龍的存在？當你在考慮要不要離開時，在眼前出現一
隻具大的火龍，嘴裡正吐出熊熊的火燄，你一個腳步不穩坐在地面，
一個念頭閃過，難不成我抱的是牠的小孩嗎？


LONG);
	setup();
	replace_program(ROOM);
}
