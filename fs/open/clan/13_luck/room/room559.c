inherit ROOM;
void create() {
	set( "short", "你會選擇什麼呢?(2)" );
	set( "owner", "dfyw" );
	set( "object", ([
		"file6"    : "/obj/gift/bingtang",
		"amount5"  : 1,
		"file5"    : "/obj/gift/lingzhi",
		"amount4"  : 1,
		"amount8"  : 1,
		"file10"   : "/obj/gift/lingzhi",
		"file9"    : "/obj/gift/bingtang",
		"amount10" : 1,
		"file2"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file8"    : "/obj/gift/lingzhi",
		"amount3"  : 1,
		"file4"    : "/obj/gift/bingtang",
		"file7"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"file3"    : "/obj/gift/lingzhi",
		"file1"    : "/obj/gift/lingzhi",
		"amount6"  : 1,
	]) );
	set( "build", 10027 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room560",
	]) );
	set( "long", @LONG
就會有那麼一段時間，我們總是忙亂於愛情、忙碌於事業、
忙命於家庭，忙慌於研愁，
最後弄得自己暈頭轉向，狼狽不堪，
然後，又會有那麼一天，某一根神經不對了，
我們倏忽停下腳步，轉身回望，竟然，覺得一切索然無味。
起初是心隨意走，後來只得跟著地球跑！
日復一日,生活不就是這樣嗎?
LONG);
	setup();
	replace_program(ROOM);
}
