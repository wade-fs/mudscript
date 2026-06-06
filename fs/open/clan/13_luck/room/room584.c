inherit ROOM;
void create() {
	set( "short", "綠色靈劍" );
	set( "owner", "basaka" );
	set( "object", ([
		"file7"    : "/open/mogi/castle/obj/seven1-dark-head",
		"file3"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount2"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount3"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount6"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file5"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file2"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount4"  : 1,
	]) );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room585.c",
		"east"      : "/open/clan/13_luck/room/room583.c",
	]) );
	set( "long", @LONG
要勇闖聚靈山莊，必先收集滿五塔主武器，分別是金塔主的金色靈
刀，木塔主的綠色靈劍，水塔主的水色絲帶，火塔主的火靈焰扇，和土
塔主的土色靈爪而在這個房間正是專門存放五塔主武器中的綠色劍，一
把散發著讓人感到詭異的綠光，據說可以有不停回復主人體力的神奇功
效，是木塔主的得意兵器。

LONG);
	setup();
	replace_program(ROOM);
}
