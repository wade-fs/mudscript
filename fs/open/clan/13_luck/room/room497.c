inherit ROOM;
void create() {
	set( "short", "星月廊道" );
	set( "owner", "mill" );
	set( "object", ([
		"amount9"  : 80,
		"amount4"  : 130,
		"file6"    : "/open/fire-hole/obj/g-pill",
		"file9"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/fire-hole/obj/k-pill",
		"amount8"  : 100,
		"amount5"  : 117,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount6"  : 199,
		"amount7"  : 210,
		"amount2"  : 300,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/fire-hole/obj/p-pill",
		"amount1"  : 300,
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file8"    : "/open/fire-hole/obj/y-pill",
		"amount3"  : 73,
	]) );
	set( "build", 10283 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room531",
		"south"     : "/open/clan/13_luck/room/room498",
		"north"     : "/open/clan/13_luck/room/room496.c",
		"east"      : "/open/clan/13_luck/room/room533.c",
	]) );
	set( "long", @LONG

    這是通往星月殿的走道，走廊四周的欄杆刻滿各類梅花和竹子的
雕刻，對應著怖滿在四周的梅花樹和竹林，紅的，白的，粉紅的，各
色梅花珍奇百豔，陣陣花香撲鼻而來，讓人陶醉在其中，而綠竹參插
在其中，正好稱拖出花的嬌豔。

LONG);
	setup();
	replace_program(ROOM);
}
