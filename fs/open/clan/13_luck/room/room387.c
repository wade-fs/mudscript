inherit ROOM;
void create() {
	set( "short", "殿內大校場二" );
	set( "object", ([
		"amount5"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"file6"    : "/obj/gift/shenliwan",
		"amount10" : 1,
		"amount3"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"file3"    : "/obj/gift/shenliwan",
		"file8"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"file10"   : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/shenliwan",
	]) );
	set( "owner", "roar" );
	set( "build", 10332 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room373",
		"south"     : "/open/clan/13_luck/room/room388.c",
		"east"      : "/open/clan/13_luck/room/room386",
	]) );
	set( "long", @LONG

    你走著走著已經來到了十三吉祥的中心地帶了，耳邊傳來一陣陣討論
的聲音，原來這裡是眾羅剎們討論十三吉祥優缺得失的地方。中央聳立著
一根通天的石柱，你可以在石柱上留下您的寶貴建議，若有不明白的地方
可以(type help board )。校場的北方是通往十三吉祥的權力中心『浪子
殿』。

LONG);
	setup();
	replace_program(ROOM);
}
