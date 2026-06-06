inherit ROOM;
void create() {
	set( "short", "前廳" );
	set( "object", ([
		"amount6"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_hands",
		"file4"    : "/open/firedancer/npc/eq/r_belt",
		"amount9"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/firedancer/npc/eq/r_pants",
		"file8"    : "/open/firedancer/npc/eq/r_boots",
		"file3"    : "/open/firedancer/npc/eq/r_cape",
		"file7"    : "/open/firedancer/npc/eq/r_shield",
		"amount5"  : 1,
		"amount10" : 1,
		"file5"    : "/open/firedancer/npc/eq/r_head",
		"amount8"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_cloth",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_leg",
		"file2"    : "/open/firedancer/npc/eq/r_neck",
		"amount1"  : 1,
	]) );
	set( "owner", "dunga" );
	set( "build", 10975 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room122",
		"north"     : "/open/clan/13_luck/room/room125",
	]) );
	set( "long", @LONG
                 
                 前廳
                                                         
四面以素質竹材布置而成，典雅大方，左右兩邊
竹窗半掩，在此特殊的地形環境下陽光總是不經
意的斜射進來，明而不烈、柔而暖溫，靠在窗邊
好似情人的手在身上游移，盡顯慵懶閒適之情，
為邪王接待摯友之所，能進門當客的武林屈指可數
LONG);
	setup();
	replace_program(ROOM);
}
