inherit ROOM;
void create() {
	set( "short", "$HIC$羅瑞安$GRN$森林$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount2"  : 84,
		"amount3"  : 14,
		"amount1"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ping/questsfan/obj/stone",
		"amount7"  : 1,
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount5"  : 5,
		"file5"    : "/open/mon/obj/mon-pill",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 1,
		"file1"    : "/open/killer/obj/fire-knife",
		"file8"    : "/open/ghost-hole/obj/dark-spirit",
		"file6"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/ghost/obj/five-turn-ball",
	]) );
	set( "build", 10021 );
	set( "exits", ([
		"west"      : "/open/clan/dark-forest/room/hall.c",
		"north"     : "/open/clan/dark-forest/room/room36",
	]) );
	set( "long", @LONG
這裡是靜謐安詳的羅瑞安森林，精靈三戒中水之戒的主人
$HIG$精靈$HIY$女皇$HIB$『$HIC$凱蘭崔爾$HIB$』$NOR$的統轄地。傳說$HIC$凱蘭崔爾$NOR$是現存中土世
界的精靈中，唯一一位見證過神之地$HIW$聖白樹$NOR$光輝的高等精靈，
她能洞察人的心思；操縱水的流動，而麾下以禁衛隊長$YEL$哈爾達$NOR$
為首的長弓隊更是戰無不勝，使中土南方出沒的半獸人聞風喪
膽。森林南邊就是大河安都因，綿延橫貫南方的河流。

LONG);
	setup();
	replace_program(ROOM);
}
