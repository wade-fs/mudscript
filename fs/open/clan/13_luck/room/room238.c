inherit ROOM;
void create() {
	set( "short", "禁地" );
	set( "owner", "zeros" );
	set( "object", ([
		"file4"    : "/obj/gift/bingtang",
		"amount10" : 1,
		"file5"    : "/obj/gift/lingzhi",
		"file10"   : "/obj/gift/bingtang",
		"amount4"  : 1,
		"file7"    : "/obj/gift/lingzhi",
		"amount6"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"amount3"  : 1,
		"file8"    : "/obj/gift/bingtang",
		"file9"    : "/obj/gift/bingtang",
		"amount8"  : 1,
		"amount7"  : 1,
		"file3"    : "/obj/gift/bingtang",
		"file1"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"file6"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10699 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room119",
		"south"     : "/open/clan/13_luck/room/room239",
	]) );
	set( "long", @LONG

這裡是夜夢宮二樓,根據歷代先祖的遺命平常這裡是禁止任何人的進出
的,就算是宮主也不能違背這項決定,除非是遇到重大災害外,否則不能動
到這裡的任何東西.正當你疑惑這怎麼會沒有任何的守護者,四周的牆上
閃出十道光芒並出現十隻護衛神獸對你說道沒是快滾不要留在這裡.

LONG);
	setup();
	replace_program(ROOM);
}
