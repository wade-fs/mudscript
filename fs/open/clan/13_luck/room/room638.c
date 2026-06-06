inherit ROOM;
void create() {
	set( "short", "驚雲閣武器房" );
	set( "object", ([
		"file6"    : "/open/capital/obj/4-1",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/mogi/dragon/obj/dragon-head",
		"amount5"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file9"    : "/open/mogi/dragon/obj/dragon-head",
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
		"file4"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount3"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10091 );
	set( "light_up", 1 );
	set( "owner", "soul" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room640",
	]) );
	set( "long", @LONG

    四周擺滿了武器，都是主人精心收集而來，各式各樣都
陳列得很整齊。牆壁上留下很多痕跡，正是演練兵器所致，
由此可見主人武功的不凡。
    四周擺滿了武器，都是主人精心收集而來，各式各樣都
陳列得很整齊。牆壁上留下很多痕跡，正是演練兵器所致，
由此可見主人武功的不凡。

LONG);
	setup();
	replace_program(ROOM);
}
