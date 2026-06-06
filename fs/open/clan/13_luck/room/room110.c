inherit ROOM;
void create() {
	set( "short", "EMC 五百障礙場" );
	set( "object", ([
		"file1"    : "/open/capital/guard/gring",
		"amount2"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
	]) );
	set( "build", 10248 );
	set( "owner", "adeyzit" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room104",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
五百障礙為訓練的重頭戲,可能有人當兵一年十個月都沒有跑過..
第一障礙高低跨欄..第二欄頗高..要注意..第二障礙為爬竿
爬竿有些技巧..臂力握的住腳夾的緊很重要..第三為板牆
第四為高跳台..第五障礙為沙坑..第六障礙為獨木橋..
第七為低襻網..兩分半跑完可是滿百的ㄛ..全副武裝帶槍跑..
LONG);
	setup();
	replace_program(ROOM);
}
