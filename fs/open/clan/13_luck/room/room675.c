inherit ROOM;
void create() {
	set( "short", "劍塚" );
	set( "owner", "sevenll" );
	set( "object", ([
		"amount6"  : 1,
		"file8"    : "/open/killer/headkill/obj/world_dag",
		"amount8"  : 1,
		"file6"    : "/open/capital/obj/4-4",
		"amount9"  : 1,
		"file2"    : "/open/gsword/obj/silver_sword",
		"file3"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/capital/obj/4-1",
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount5"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/wind-rain/obj/bird-blade",
		"amount3"  : 1,
		"file1"    : "/open/gsword/obj1/blosword",
		"amount7"  : 1,
	]) );
	set( "build", 10076 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room673.c",
		"out"       : "/open/clan/13_luck/room/room676",
		"west"      : "/open/clan/13_luck/room/room674.c",
		"south"     : "/open/clan/13_luck/room/room689",
		"north"     : "/open/clan/13_luck/room/room672.c",
	]) );
	set( "long", @LONG
    這裡到處都是劍的碎片,你感到十分的奇怪,為何在這個瀑
布裡會有這麼多碎劍,你抬頭一看,牆壁上放滿了許多的寶劍!!
其中有一把閃閃發光,而且劍鞘還留有餘溫,或許主人還沒有離
開這個地方多久,你快步前進,不敢逗留

LONG);
	setup();
	replace_program(ROOM);
}
