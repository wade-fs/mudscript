inherit ROOM;
void create() {
	set( "short", "逍遙人間道" );
	set( "object", ([
		"file9"    : "/open/firedancer/npc/eq/r_head",
		"amount8"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_shield",
		"file7"    : "/open/firedancer/npc/eq/r_cape",
		"amount9"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_boots",
		"amount4"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_neck",
		"amount10" : 1,
		"amount6"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_pants",
		"amount7"  : 1,
		"file10"   : "/open/firedancer/npc/eq/r_cloth",
		"file5"    : "/open/firedancer/npc/eq/r_belt",
		"file8"    : "/open/firedancer/npc/eq/r_hands",
		"amount5"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_armbands",
	]) );
	set( "build", 10320 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room162",
		"south"     : "/open/clan/13_luck/room/room165.c",
	]) );
	set( "long", @LONG

　　此道鳥雨花香，樹木叢立，此道為大杯綠茶所命名的，幫派成立
後，大杯綠茶經常去找千年樹妖泡茶聊天，喝咖啡，聊是非‧有空也
會來陪他抽個煙，跟他熟的不得了，去一趟還會跟他拿些保護費，及
借些妖幻系列的裝備還用用，使幫內不餘匱乏。倩女幽魂看太多了..

LONG);
	setup();
	replace_program(ROOM);
}
