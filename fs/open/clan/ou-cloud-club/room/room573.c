inherit ROOM;
void create() {
	set( "short", "$HIC$奇犽‧揍敵客$HIW$ソ$HIR$武器$HIY$裝備室$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"file4"    : "/open/capital/obj/4-3",
		"amount7"  : 1,
		"file7"    : "/open/capital/obj/4-3",
		"file2"    : "/open/capital/obj/4-3",
		"amount8"  : 1,
		"file9"    : "/open/killer/obj/dagger",
		"amount9"  : 1,
		"amount10" : 1,
		"amount5"  : 1,
		"file5"    : "/open/capital/obj/4-4",
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"file8"    : "/open/killer/headkill/obj/world_dag",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/killer/obj/fire-knife",
		"amount2"  : 1,
	]) );
	set( "build", 10020 );
	set( "owner", "killua" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room453",
	]) );
	set( "long", @LONG

    這裡是奇犽‧揍敵客平常放置武器的地方，雖然他很少使用
武器，不過還是擺著許許多多、琳瑯滿目的武器，以備不時之需
。正當你看的眼花撩亂之際，咦？地上怎麼會有兩個溜溜球？難
道溜溜球也可以當作武器嗎？？？

LONG);
	setup();
	replace_program(ROOM);
}
