inherit ROOM;
void create() {
	set( "short", "土色靈爪" );
	set( "owner", "basaka" );
	set( "build", 12966 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room586.c",
		"north"     : "/open/clan/13_luck/room/room584.c",
	]) );
	set( "long", @LONG
要勇闖聚靈山莊，必先收集滿五塔主武器，分別是金塔主的金色靈
刀，木塔主的綠色靈劍，水塔主的水色絲帶，火塔主的火靈焰扇，和土
塔主的土色靈爪而在這個房間正是專門存放五塔主武器中的土色爪，當
他發出金色亮光時可以讓敵人眼睛受傷，而暫時無法攻擊，是金塔主的
得意兵器，配合金塔主的無影刀法，簡直是天下無敵。

LONG);
	setup();
	replace_program(ROOM);
}
