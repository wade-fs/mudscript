inherit ROOM;
void create() {
	set( "short", "$HIC$奇犽‧揍敵客$HIW$ソ$HIR$遊$HIY$戲$HIG$屋$NOR$" );
	set( "object", ([
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"file10"   : "/obj/gift/xiandan",
		"file2"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"amount5"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/obj/gift/lingzhi",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10218 );
	set( "owner", "killua" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room719",
	]) );
	set( "long", @LONG

    這裡是奇犽‧揍敵客ソ遊戲屋。平常練功累了，他都會跑來
這裡打電動。滿地的主機跟卡匣，從紅白機、ＳＥＧＡ、超任、
Ｓａｔｕｒｎ、ＰＳ、ＰＳ２、Ｎｉｎｔｅｎｄｏ６４、Ｇａｍ
ｅｂｏｙ、Ｇａｍｅｃｕｂｅ等等多的不勝枚舉，甚至連最新的
ＸＢＯＸ都有。

LONG);
	setup();
	replace_program(ROOM);
}
