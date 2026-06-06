inherit ROOM;
void create() {
	set( "short", "Ｍｏｉ的戰利品儲藏室" );
	set( "owner", "blackdog" );
	set( "build", 10321 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room636",
		"west"      : "/open/clan/13_luck/room/room98.c",
	]) );
	set( "long", @LONG

這裡是烈兒的戰利品儲藏室，一進來你就發現好像很擠，想找個位置
站都很難，因為房間裡塞滿了各地收來的戰利品，雖然有些價值並不
高，但是自己花時間辛苦取得的東西總是捨不得丟棄的。
仔細看看，這房間還勉強算的上是亂中有序，各項物品都分門別類擺
的好好的，各項物品都可以隨時取用，讓人帶著出去征戰呢。

LONG);
	setup();
	replace_program(ROOM);
}
