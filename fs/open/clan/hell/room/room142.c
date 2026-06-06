inherit ROOM;
void create() {
	set( "short", "岩岸" );
	set( "exits", ([
		"down"      : "/open/clan/hell/room/room135",
		"east"      : "/open/clan/hell/room/room94.c",
	]) );
	set( "long", @LONG
海水打在岸邊的岩石上,不斷地濺起一波波的水花,這裡的石頭成年被海水
侵蝕,上面佈滿了大大小小的洞,而且異常滑溜,想在上面行走,輕功必要有一定
的水準,否則很容易落海而死,站在比較高的石塊往島上望去,似乎在東邊有一片
比較平坦的沙岸,岩岸的北邊是一面峭壁.

LONG);
	setup();
	replace_program(ROOM);
}
