inherit ROOM;
void create() {
	set( "short", "青石板道" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/dancer/obj/yuawaist",
		"amount6"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/mon/obj/ghost-claw",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
	]) );
	set( "build", 10234 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room526.c",
		"south"     : "/open/clan/13_luck/room/room522",
		"east"      : "/open/clan/13_luck/room/room528.c",
	]) );
	set( "long", @LONG
從大門延伸過來通往前堂的青石板道，路的板磚似乎還是新換的，
在板磚上雕刻著無數的人名，這些人名都是在任務中奉獻出生命的人，
因此這青石板道又是為了紀念他所以建造的，看著看著於是漸漸走向前
方這歷史悠久，有著如傳說般過去的建築物，心裡突然感到一陣悸動。
LONG);
	setup();
	replace_program(ROOM);
}
