inherit ROOM;
void create() {
	set( "short", "水色絲帶" );
	set( "owner", "basaka" );
	set( "build", 11056 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room545.c",
		"north"     : "/open/clan/13_luck/room/room585.c",
	]) );
	set( "long", @LONG
要勇闖聚靈山莊，必先收集滿五塔主武器，分別是金塔主的金色靈
刀，木塔主的綠色靈劍，水塔主的水色絲帶，火塔主的火靈焰扇，和土
塔主的土色靈爪而在這個房間正是專門存放五塔主武器中的水色絲帶，
天藍色的絲帶隱藏著一個秘密，就是可以不停吸取敵人內力並且恢復主
人內力的神奇功效，是水塔主的得意兵器。

LONG);
	setup();
	replace_program(ROOM);
}
