inherit ROOM;
void create() {
	set( "short", "拍賣屋東側盡頭" );
	set( "object", ([
		"file3"    : "/obj/gift/bingtang",
		"file4"    : "/open/killer/obj/fire-knife",
		"file8"    : "/open/killer/obj/fire-knife",
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"amount4"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/killer/obj/fire-knife",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/killer/obj/fire-knife",
		"amount1"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/killer/obj/fire-knife",
		"file6"    : "/open/killer/obj/fire-knife",
		"amount3"  : 1,
	]) );
	set( "build", 14689 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room492.c",
		"north"     : "/open/clan/sky-wu-chi/room/room494",
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
