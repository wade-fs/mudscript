inherit ROOM;
void create() {
	set( "short", "$HIC$奇犽‧揍敵客$HIW$ソ$HIR$遊$HIY$戲$HIG$屋$NOR$" );
	set( "object", ([
		"file4"    : "/obj/gift/lingzhi",
		"file2"    : "/obj/gift/lingzhi",
		"amount7"  : 1,
		"file3"    : "/obj/gift/lingzhi",
		"amount6"  : 1,
		"file7"    : "/obj/gift/lingzhi",
		"amount5"  : 1,
		"amount3"  : 1,
		"file5"    : "/obj/gift/bingtang",
		"file8"    : "/obj/gift/bingtang",
		"file10"   : "/obj/gift/bingtang",
		"amount9"  : 1,
		"file6"    : "/obj/gift/bingtang",
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file9"    : "/obj/gift/bingtang",
		"file1"    : "/obj/gift/bingtang",
	]) );
	set( "build", 11427 );
	set( "owner", "killua" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room719",
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
