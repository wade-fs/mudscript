inherit ROOM;
void create() {
	set( "short", "金色靈刀" );
	set( "owner", "basaka" );
	set( "object", ([
		"file2"    : "/open/mogi/dragon/obj/dragon-head",
		"amount4"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
	]) );
	set( "build", 10719 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room749",
		"north"     : "/open/clan/13_luck/room/room586.c",
	]) );
	set( "long", @LONG
要勇闖聚靈山莊，必先收集滿五塔主武器，分別是金塔主的金色靈
刀，木塔主的綠色靈劍，水塔主的水色絲帶，火塔主的火靈焰扇，和土
塔主的土色靈爪而在這個房間正是專門存放五塔主武器中的金色靈刀，
當他發出金色亮光時可以讓敵人眼睛受傷，而暫時無法攻擊，是金塔主
的得意兵器，配合金塔主的無影刀法，天下無敵。

LONG);
	setup();
	replace_program(ROOM);
}
