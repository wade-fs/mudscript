inherit ROOM;
void create() {
	set( "short", "拍賣屋東側環道" );
	set( "object", ([
		"file3"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"file1"    : "/open/killer/obj/fire-knife",
		"file9"    : "/obj/gift/hobowdan",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
	]) );
	set( "build", 10449 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room493",
		"north"     : "/open/clan/sky-wu-chi/room/room495",
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
