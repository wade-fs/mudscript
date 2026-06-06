inherit ROOM;
void create() {
	set( "short", "$CYN$ξ漩渦ξ$NOR$" );
	set( "owner", "coling" );
	set( "object", ([
		"file7"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount5"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/mogi/castle/obj/white-ghost-head",
		"file8"    : "/open/mogi/dragon/obj/dragon-head",
		"amount6"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file2"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file4"    : "/open/mogi/castle/obj/seven4-dark-head",
		"amount2"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/mogi/castle/obj/black-ghost-head",
		"file1"    : "/open/mogi/castle/obj/seven1-dark-head",
		"file3"    : "/open/mogi/castle/obj/seven3-dark-head",
		"file5"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount7"  : 1,
	]) );
	set( "build", 11019 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room457.c",
		"south"     : "/open/clan/sky-wu-chi/room/room458",
		"east"      : "/open/clan/sky-wu-chi/room/room455.c",
		"cho"       : "/open/clan/sky-wu-chi/room/hall",
		"west"      : "/open/clan/sky-wu-chi/room/room456.c",
	]) );
	set( "long", @LONG
  超巨大的$CYN$漩渦$NOR$！！  乘著竹筏的你在也不能控制！！！
  人連竹筏就被$CYN$漩渦$NOR$吸了進去！！轉的讓你分不清東南西北，
  心想如何逃離這個浩劫！！！！.........................

  $HIR$然而你突然眼前一黑，不支體力的倒在地上$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
