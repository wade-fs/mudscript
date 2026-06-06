inherit ROOM;
void create() {
	set( "short", "殿內大校場一" );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file6"    : "/obj/gift/lingzhi",
		"amount6"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount9"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"amount2"  : 1,
		"file9"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/unknowdan",
		"file3"    : "/obj/gift/lingzhi",
		"amount10" : 1,
		"file8"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/gift/unknowdan",
	]) );
	set( "owner", "roar" );
	set( "build", 11139 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room389.c",
		"north"     : "/open/clan/13_luck/room/room387",
	]) );
	set( "long", @LONG

    經過漫長的殿前大道終於來到了浪子殿前的大校場，這個大校場是可
以連接十三吉祥各個部門的重要據點，你可以在這裡便聽到大校場上有不
少打鬥的聲音，十三吉祥裡的門生都必須要在這裡打敗敵人甚或自己的師
長，才有可能獲得升遷的機會，打鬥的慘烈可想而知。往北則到校場的正
中央，在那有根石柱供玩家留言。

LONG);
	setup();
	replace_program(ROOM);
}
