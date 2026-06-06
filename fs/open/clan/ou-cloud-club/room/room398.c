inherit ROOM;
void create() {
	set( "short", "$HIY$聚靈池$NOR$" );
	set( "owner", "dracula" );
	set( "object", ([
		"amount5"  : 1078,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 36,
		"file4"    : "/open/mon/obj/mon-pill",
		"amount2"  : 1600,
		"file8"    : "/open/ghost-hole/obj/fire-spirit",
		"amount4"  : 168,
		"file3"    : "/open/ping/obj/poison_pill",
		"amount1"  : 660,
		"file1"    : "/open/fire-hole/obj/k-pill",
		"file2"    : "/open/killer/obj/atman_pill",
		"amount7"  : 1,
		"amount8"  : 1,
		"file7"    : "/obj/gift/lingzhi",
	]) );
	set( "build", 16746 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room109",
	]) );
	set( "long", @LONG
聚靈池，是聚靈山莊的一個奇特的池子，山莊飄散出來的靈氣大
都會飄往這裏，最後被聚靈池吸收，在聚靈池中心，聚集著強大的靈
氣，愈往池中心，靈氣愈是強烈，並聚成五彩靈光，在池中來來回回
的穿越奔騰，剎是好看。

LONG);
	setup();
	replace_program(ROOM);
}
