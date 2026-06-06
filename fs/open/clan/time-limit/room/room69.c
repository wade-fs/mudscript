inherit ROOM;
void create() {
	set( "short", "$HIG$海格$HIB$的$HIY$木屋$NOR$" );
	set( "owner", "goldblade" );
	set( "object", ([
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10420 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room67",
		"east"      : "/open/clan/time-limit/room/room70.c",
		"north"     : "/open/clan/time-limit/room/room68.c",
	]) );
	set( "long", @LONG
海格的木屋位於禁忌森林的入口,一方面可以監控學生進入禁忌森林,
另一方面也可以防止森林的猛獸進入校園,一進入木屋,
獵豬犬-牙牙馬上撲了過來,熱情的舔著你臉頰,木屋上掛著臘肉,
窗戶旁掛著石弓,爐火讓你的身體暖和了起來,海格在家時會招待你喝茶,
還有他拿手的石頭蛋糕,不過海格的手藝讓人不敢領教,
吃他所做的石頭蛋糕說不定會把牙齒給崩斷

LONG);
	setup();
	replace_program(ROOM);
}
