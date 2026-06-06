inherit ROOM;
void create() {
	set( "short", "$HIC$奇犽‧揍敵客$HIW$ソ$HIR$遊$HIY$戲$HIG$屋$NOR$" );
	set( "object", ([
		"amount5"  : 1,
		"file6"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/unknowdan",
		"amount2"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"amount10" : 1,
		"file4"    : "/obj/gift/xisuidan",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
	]) );
	set( "build", 11510 );
	set( "owner", "killua" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room721",
		"down"      : "/open/clan/ou-cloud-club/room/room453.c",
		"south"     : "/open/clan/ou-cloud-club/room/room720",
		"west"      : "/open/clan/ou-cloud-club/room/room723",
		"north"     : "/open/clan/ou-cloud-club/room/room722",
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
