inherit ROOM;
void create() {
	set( "short", "武神居防具房" );
	set( "object", ([
		"amount6"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount5"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount9"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount2"  : 1,
		"amount10" : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount4"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount1"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount7"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-boots",
	]) );
	set( "build", 10223 );
	set( "owner", "zmud" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room679",
	]) );
	set( "long", @LONG

    四周呈列了各式各樣的防具，這些都是武神的最愛。
每一件防具都有其特殊的功用，穿在每一個人身上都會有
不一樣的功能，不平凡的功能。面對不同的挑戰，武神為
求全力以赴，必定挑選最適合的防具，精銳盡出，這正是
對求教者的尊重。

LONG);
	setup();
	replace_program(ROOM);
}
