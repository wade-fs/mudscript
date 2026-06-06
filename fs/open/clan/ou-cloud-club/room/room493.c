inherit ROOM;
void create() {
	set( "short", "金來火葬場" );
	set( "owner", "ctx" );
	set( "object", ([
		"file10"   : "/obj/gift/bingtang",
		"file3"    : "/obj/gift/bingtang",
		"file7"    : "/obj/gift/bingtang",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file8"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"amount6"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"file6"    : "/obj/gift/bingtang",
		"amount5"  : 1,
		"file5"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"file9"    : "/obj/gift/lingzhi",
		"file4"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"amount10" : 1,
		"file1"    : "/obj/gift/bingtang",
	]) );
	set( "build", 11276 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room495",
	]) );
	set( "long", @LONG
看到這裡一個個的火爐就知道這裡不是焚化爐就是火葬場了
不過在看到火爐前一個個準備放進去焚燒的棺木, 大概沒人會想
說這裡是焚化爐吧,此外這個焚化爐除了焚化一般棺木外,為了順
應民情,如果還要順便燒一些紙錢還是紙車等等的,也是可以在這
邊處理的,歡迎多多利用。

LONG);
	setup();
	replace_program(ROOM);
}
