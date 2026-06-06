inherit ROOM;
void create() {
	set( "short", "殿內大道三" );
	set( "object", ([
		"amount8"  : 1,
		"amount5"  : 1,
		"file6"    : "/obj/gift/lingzhi",
		"file9"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file7"    : "/obj/gift/lingzhi",
		"amount4"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"file8"    : "/obj/gift/bingtang",
		"file3"    : "/obj/gift/lingzhi",
		"amount1"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"file5"    : "/obj/gift/bingtang",
		"file10"   : "/obj/gift/bingtang",
		"file4"    : "/obj/gift/lingzhi",
	]) );
	set( "owner", "roar" );
	set( "build", 10296 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room390",
		"north"     : "/open/clan/13_luck/room/room388",
	]) );
	set( "long", @LONG

    前方傳來一陣陣的打鬥聲，原來再往前走就到十三吉祥的校場了，而
裡的陰陽兩股氣流也沒之前來的嚴重了，而兩旁亦出現代表十三吉祥浪子
殿的旗幟，旗上繡有代表十三吉祥無上權威的青龍和白虎，浪子殿的影像
亦逐漸浮現在眼前了。

LONG);
	setup();
	replace_program(ROOM);
}
