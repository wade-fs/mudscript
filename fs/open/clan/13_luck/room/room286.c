inherit ROOM;
void create() {
	set( "short", "七彩陣入口" );
	set( "object", ([
		"file9"    : "/open/mon/obj/thousand-nectar",
		"file3"    : "/open/fire-hole/obj/y-pill",
		"amount8"  : 190,
		"amount2"  : 575,
		"file6"    : "/open/fire-hole/obj/w-pill",
		"amount3"  : 894,
		"amount7"  : 698,
		"file7"    : "/open/fire-hole/obj/k-pill",
		"file4"    : "/open/fire-hole/obj/p-pill",
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file8"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/fire-hole/obj/b-pill",
		"amount4"  : 650,
		"amount9"  : 36,
		"amount6"  : 300,
		"amount5"  : 500,
		"file10"   : "/open/magic-manor/obj/lunar-heart",
		"amount10" : 1,
	]) );
	set( "owner", "zmud" );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room661",
		"north"     : "/open/clan/13_luck/room/room341.c",
		"out"       : "/open/clan/13_luck/room/room44.c",
	]) );
	set( "build", 10515 );
	set( "light_up", 1 );
	set( "long", @LONG

    進入宏偉的武神居大門之後，來到七彩陣入口。由紅、
橙、黃、綠、藍、靛、紫七彩構成的陣法，正是通往『武神
居』的必經之路，只有勇者才能憑著高超的修為，通過層層
考驗，順利闖關通過，見到傳說中的武神。

LONG);
	setup();
	replace_program(ROOM);
}
