inherit ROOM;
void create() {
	set( "short", "$HIG$≡雲飛何處≡$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"amount10" : 1,
		"amount8"  : 1,
		"file7"    : "/open/gsword/obj1/bpball",
		"file10"   : "/open/gsword/obj1/bpball",
		"amount5"  : 1,
		"file1"    : "/open/ping/obj/ring-2",
		"amount4"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"file2"    : "/open/mogi/dragon/obj/dragon-head",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
	]) );
	set( "build", 12129 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room323.c",
	]) );
	set( "long", @LONG
雲飛揚-------走遍大江南北所搜集的古玩武器
雲飛揚-------走遍大江南北所搜集的古玩武器珍寶
雲飛揚-------走遍大江南北所搜集的古玩武器珍寶
雲飛揚-------走遍大江南北所搜集的古玩武器珍寶
雲飛揚-------走遍大江南北所搜集的古玩武器珍寶
雲飛揚-------走遍大江南北所搜集的古玩武器珍寶

LONG);
	setup();
	replace_program(ROOM);
}
