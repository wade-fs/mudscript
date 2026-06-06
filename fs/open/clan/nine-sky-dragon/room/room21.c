inherit ROOM;
void create() {
	set( "short", "幸福的預感" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10602 );
	set( "exits", ([
		"south"     : "/open/clan/nine-sky-dragon/room/room20",
	]) );
	set( "long", @LONG
天空裡為什麼蔚藍 是你的心在天際對著我呼喚
今天起醒來不再孤獨 想見到你我就有幸福的預感
我融化在你的笑容 你的懷中 你讓我再一次 再一次的想起你(想起你)
我多麼盼望這一秒 想告訴你 你的愛給我溫暖 讓我自由的飛
如果你需要一個答案 把那封信打開來你就會明白
如果你有點看不清楚 把我的心打開來 讓你看明白
我躲不開你的溫柔 你的溫柔 你讓我再一次 再一次的愛上你(愛上你)
我多麼盼望這一秒 想告訴你 你的愛給我力量 讓我勇敢的飛
喔 不管多煎熬 不管有時心被傷痛 不管歲月 也不管能否天荒地老
LONG);
	setup();
	replace_program(ROOM);
}
