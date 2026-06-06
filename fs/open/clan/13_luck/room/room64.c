inherit ROOM;
void create() {
	set( "short", "混沌" );
	set( "owner", "papt" );
	set( "object", ([
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount10" : 151,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file2"    : "/open/prayer/obj/boris-cloth",
		"amount2"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file10"   : "/open/killer/obj/hate_knife",
		"file3"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file6"    : "/open/dancer/obj/yuawaist",
		"file8"    : "/daemon/class/fighter/armband",
	]) );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room62",
	]) );
	set( "light_up", 1 );
	set( "build", 10078 );
	set( "long", @LONG

    這裡是一個與外界完全不同的地方，沒有任何的景物，沒有任何的
顏色只是一片純白的世界,讓人匪夷所思,在這其中隱約看的到一個人盤
腿而坐在其中，他就是數十年前叱吒風雲的一位高人，至於他為何會在
這裡，那也只有等你自己去問他了．

LONG);
	setup();
	replace_program(ROOM);
}
