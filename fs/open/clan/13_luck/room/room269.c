inherit ROOM;
void create() {
	set( "short", "陽炎臂環室" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount6"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount10" : 1,
		"amount4"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room280",
		"south"     : "/open/clan/13_luck/room/room298.c",
	]) );
	set( "build", 10083 );
	set( "light_up", 1 );
	set( "long", @LONG

    隴山，聞之變色的隴山派，那個出自任正晴之手的浩日訣，手上的
炎陽臂環，也是不錯的防具，但要得到他要先打敗任正晴或他兒子，幸
好有他兒子在，不然，憑他的浩日訣要在他手上要東西，可以說是難矣
，看到五線譜，眼前一黑，什麼都不知道了。

LONG);
	setup();
	replace_program(ROOM);
}
