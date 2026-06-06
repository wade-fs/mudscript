inherit ROOM;
void create() {
	set( "short", "$HIC$奇犽‧揍敵客$HIW$ソ$HIR$遊$HIY$戲$HIG$屋$NOR$" );
	set( "object", ([
		"file8"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"file3"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/gift/shenliwan",
		"file5"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10156 );
	set( "owner", "killua" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room719",
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
