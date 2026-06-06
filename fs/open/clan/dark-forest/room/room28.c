inherit ROOM;
void create() {
	set( "short", "硬的大廳" );
	set( "owner", "robo" );
	set( "object", ([
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file8"    : "/open/fire-hole/obj/y-pill",
		"amount8"  : 1,
		"amount9"  : 18,
		"amount3"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/fire-hole/obj/y-pill",
		"amount1"  : 2,
		"amount6"  : 1,
		"file9"    : "/open/mon/obj/mon-pill",
		"amount7"  : 2,
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
		"file2"    : "/obj/gift/shenliwan",
		"file7"    : "/open/fire-hole/obj/p-pill",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount4"  : 1,
		"file1"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "build", 10128 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/dark-forest/room/room29",
		"east"      : "/open/clan/dark-forest/room/room16",
	]) );
	set( "long", @LONG
硬硬硬硬硬硬　　的的的的的的　　大大大大大大　　廳廳廳廳廳廳
　　硬硬硬硬硬硬　　的的的的的的　　大大大大大大　　廳廳廳廳廳廳
　　硬硬硬硬硬硬　　的的的的的的　　大大大大大大　　廳廳廳廳廳廳
　　硬硬硬硬硬硬　　的的的的的的　　大大大大大大　　廳廳廳廳廳廳
　　硬硬硬硬硬硬　　的的的的的的　　大大大大大大　　廳廳廳廳廳廳
　　硬硬硬硬硬硬　　的的的的的的　　大大大大大大　　廳廳廳廳廳廳
LONG);
	setup();
	replace_program(ROOM);
}
