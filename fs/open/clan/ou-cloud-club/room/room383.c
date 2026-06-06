inherit ROOM;
void create() {
	set( "short", "$HIG$大風起兮$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"amount1"  : 34,
		"file5"    : "/open/ping/obj/cloud_fan",
		"file3"    : "/open/ping/obj/neck0",
		"amount8"  : 1,
		"amount10" : 1,
		"file7"    : "/open/ping/obj/cloud_fan",
		"file10"   : "/open/ping/questsfan/obj/diamond_legging",
		"amount5"  : 1,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"amount4"  : 1,
		"file4"    : "/open/gsword/obj1/bpball",
		"file9"    : "/open/scholar/obj/icefan",
		"file6"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"file2"    : "/open/ping/questsfan/obj/diamond_hands",
		"amount3"  : 1,
		"file8"    : "/open/ping/questsfan/obj/diamond_belt",
	]) );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room323",
	]) );
	set( "build", 10291 );
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
