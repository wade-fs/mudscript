inherit ROOM;
void create() {
	set( "short", "$BRED$三$BCYN$根$BYEL$掃$BWHT$帚$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10078 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room7",
		"east"      : "/open/clan/time-limit/room/room5",
	]) );
	set( "long", @LONG
三根掃帚是活米村最熱鬧的地方,老闆是羅梅塔夫人,她是位美麗的女巫
,正在店裡忙著招呼客人,而她也是這間店的活招牌,
連魔法部長-康尼留斯都親自來光顧,另外榮恩-衛斯理也在一角,
一邊喝著奶油啤酒,一邊偷偷看著羅梅塔夫人,
一位客人喝完酒一時興起,便開始大聲唱歌

LONG);
	setup();
	replace_program(ROOM);
}
