inherit ROOM;
void create() {
	set( "short", "吉祥埋刀室" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount9"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount2"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount1"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount8"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount3"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount6"  : 1,
		"amount7"  : 1,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room268",
	]) );
	set( "build", 10455 );
	set( "light_up", 1 );
	set( "long", @LONG

    刀者，武器之霸者，幻想中的兩大刀派，魔刀跟金刀，都是無人不
知的強力門派，加上好刀，更是得心應手，戰無不勝，所以打把好刀真
的不容易，因為太難打了，隨時都有我不入地獄，誰入地獄的準備去打
把好刀，所以希望能珍惜。

LONG);
	setup();
	replace_program(ROOM);
}
