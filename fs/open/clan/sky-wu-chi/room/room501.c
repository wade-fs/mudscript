inherit ROOM;
void create() {
	set( "short", "拍賣屋西側盡頭" );
	set( "object", ([
		"amount4"  : 1,
		"amount10" : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/capital/obj/4-3",
		"file7"    : "/open/capital/obj/4-3",
		"amount3"  : 1,
		"file1"    : "/open/capital/obj/4-3",
		"file3"    : "/open/capital/obj/4-3",
		"file8"    : "/open/capital/obj/4-3",
		"amount6"  : 1,
		"file9"    : "/open/capital/obj/4-3",
		"file6"    : "/open/capital/obj/4-3",
		"amount5"  : 1,
		"file5"    : "/open/capital/obj/4-3",
		"file10"   : "/open/capital/obj/4-3",
	]) );
	set( "build", 10439 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room502",
		"north"     : "/open/clan/sky-wu-chi/room/room500",
	]) );
	set( "long", @LONG
這裡是拍賣屋西側走道，旁邊擺著許許多多美麗的花盆與一福福美美的圖
畫，讓你心裡起了很大的疑惑，難道這些都是準備要賣的東西嗎？沒錯，這些
就是Giga大賣商準備用來拍賣的東西，旁邊還有許多的儲櫃，裡面更擺著你想
要的裝備與武器呢！
LONG);
	setup();
	replace_program(ROOM);
}
