inherit ROOM;
void create() {
	set( "short", "$HIC$死靈骨魔爪牙Ⅱ$NOR$" );
	set( "owner", "snowy" );
	set( "object", ([
		"amount8"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount1"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount7"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10270 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room358",
	]) );
	set( "long", @LONG
骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙
死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙
死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙
死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙
死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙
死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙死靈骨魔爪牙
LONG);
	setup();
	replace_program(ROOM);
}
