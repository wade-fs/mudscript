inherit ROOM;
void create() {
	set( "short", "浪子居右殿" );
	set( "object", ([
		"amount6"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/obj/fire-ball",
		"file6"    : "/open/magic-manor/obj/soil-ball",
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"amount10" : 1,
		"file3"    : "/open/magic-manor/obj/wood-ball",
		"amount5"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/obj/wood-ball",
		"amount1"  : 9,
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file9"    : "/open/magic-manor/obj/wood-ball",
		"file8"    : "/open/magic-manor/obj/golden-ball",
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/obj/wood-ball",
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"amount8"  : 1,
	]) );
	set( "owner", "roar" );
	set( "light_up", 1 );
	set( "build", 10341 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room88",
	]) );
	set( "long", @LONG
這裡是浪子居的右殿，牆上的石壁刻劃著當年風魔浪子解三斬，刀皇和妖刀
的戰況。當初浪子之所以沒傲笑整個武林的最大原因便是在這三個沒完全解到，
原本離武林刀王之位僅差一步，就因狂想重開而中斷。故其怒言道：
                
                『總有一日，要天下武林再度染血。』

LONG);
	setup();
	replace_program(ROOM);
}
