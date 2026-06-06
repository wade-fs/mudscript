inherit ROOM;
void create() {
	set( "short", "$HIW$黑輪臥房 - $HIC$防具室$NOR$" );
	set( "owner", "radio" );
	set( "object", ([
		"amount2"  : 1,
		"file4"    : "/open/killer/obj/k_ring",
		"amount1"  : 1,
		"file3"    : "/open/killer/obj/k_ring",
		"amount4"  : 1,
		"file1"    : "/open/killer/obj/k_ring",
		"file2"    : "/open/killer/obj/k_ring",
		"amount3"  : 1,
	]) );
	set( "build", 10224 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room41.c",
		"south"     : "/open/clan/hell/room/room52",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡便是房具室了，這裡滿是難得一見的房具
不論是鐵布杉、金縷衣、甚至焚天魔王所穿戴之房
具，都沒有遺漏，你不禁心想究竟黑輪是有何通天
的本領能取得這些東西阿‧

LONG);
	setup();
	replace_program(ROOM);
}
