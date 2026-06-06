inherit ROOM;
void create() {
	set( "short", "拍賣屋東北轉角" );
	set( "object", ([
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/gsword/obj1/kring",
		"amount1"  : 1,
		"file6"    : "/open/wu/obj/armband",
		"file2"    : "/open/gsword/obj1/karmor",
		"amount6"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/killer/obj/fire-knife",
		"amount3"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 15134 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room496",
		"south"     : "/open/clan/sky-wu-chi/room/room494",
	]) );
	set( "long", @LONG
這裡是拍賣屋東側走道，旁邊擺著許許多多美麗的花盆與一福福美美的圖
畫，讓你心裡起了很大的疑惑，難道這些都是準備要賣的東西嗎？沒錯，這些
就是Giga大賣商準備用來拍賣的東西，旁邊還有許多的儲櫃，裡面更擺著你想
要的裝備與武器呢！
LONG);
	setup();
	replace_program(ROOM);
}
