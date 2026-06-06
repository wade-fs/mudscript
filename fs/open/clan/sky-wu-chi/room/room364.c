inherit ROOM;
void create() {
	set( "short", "幽谷筱築" );
	set( "owner", "sblade" );
	set( "object", ([
		"amount6"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"file8"    : "/open/firedancer/npc/eq/r_finger",
		"file2"    : "/open/firedancer/npc/eq/r_pants",
		"file4"    : "/open/firedancer/npc/eq/r_leg",
		"file3"    : "/open/firedancer/npc/eq/r_neck",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_head",
		"amount5"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_cape",
		"file10"   : "/open/firedancer/npc/eq/r_belt",
		"file6"    : "/open/firedancer/npc/eq/r_hands",
		"amount7"  : 1,
		"file7"    : "/open/firedancer/npc/eq/r_cloth",
		"amount1"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_shield",
	]) );
	set( "light_up", 1 );
	set( "build", 11082 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room365.c",
		"west"      : "/open/clan/sky-wu-chi/room/room299.c",
	]) );
	set( "long", @LONG
    這裡是一座隱藏的山谷，四週雲煙裊裊，若非有人帶領，很難發
現小路後別有洞天。一望此處，只見遍地百花齊放豔麗非凡，耳中傳
來各種飛禽鳴叫聲，霧氣濛濛地在身邊繚繞著，混然融合為一體彷彿
是天外仙境一般，讓人有股清心脫俗之感，而此處正是高手如雲的幽
谷筱築總壇所在。空氣中飄散著絲絲冰沏入心的泉水，隱隱約約的看
到水氣在『冰沏石』心上形成對對詩句，好像是前人所留下。由此處
往東走可以進入《筱築石室》
LONG);
	setup();
	replace_program(ROOM);
}
