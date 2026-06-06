inherit ROOM;
void create() {
	set( "short", "拍賣屋北方轉角" );
	set( "object", ([
		"file1"    : "/open/capital/obj/4-3",
		"file4"    : "/open/capital/obj/4-3",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/capital/obj/4-3",
	]) );
	set( "build", 10502 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room498",
		"east"      : "/open/clan/sky-wu-chi/room/room496.c",
	]) );
	set( "long", @LONG
這裡是拍賣屋北方轉角，旁邊擺著許許多多美麗的花盆與一福福美美的圖
畫，讓你心裡起了很大的疑惑，難道這些都是準備要賣的東西嗎？沒錯，這些
就是Giga大賣商準備用來拍賣的東西，旁邊還有許多的儲櫃，裡面更擺著你想
要的裝備與武器呢！
LONG);
	setup();
	replace_program(ROOM);
}
