inherit ROOM;
void create() {
	set( "short", "浪子居左殿" );
	set( "object", ([
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/daemon/class/blademan/obj/skykey",
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/daemon/class/blademan/obj/wstone",
		"file6"    : "/daemon/class/blademan/obj/hstone",
		"file1"    : "/daemon/class/blademan/obj/gstone",
		"amount9"  : 1,
		"amount10" : 1,
		"file3"    : "/daemon/class/blademan/obj/fstone",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"file5"    : "/daemon/class/blademan/obj/estone",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"file2"    : "/daemon/class/blademan/obj/wastone",
		"amount1"  : 1,
		"amount6"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 12870 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room88",
	]) );
	set( "long", @LONG
浪子居左殿，地上鋪著紅色的波斯地毯，兩旁各有一排琉璃燈柱，燈
所散發出的光芒照曜著整個浪子居，中間擺著一面黑色檀木所造的大型圓
桌。原來這裡是浪子與十三吉祥各大玩家開會的地方，若遇到緊急事故則
遠方的首強幫派-傲雲山莊亦會來到這商討作戰大計。
LONG);
	setup();
	replace_program(ROOM);
}
