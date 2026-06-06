inherit ROOM;
void create() {
	set( "short", "$HIC$天空之城$NOR$--$HIY$雲石之一$NOR$" );
	set( "object", ([
		"file3"    : "/open/firedancer/npc/eq/r_finger",
		"amount2"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_cloth",
		"amount8"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_shield",
		"amount10" : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_head",
		"file10"   : "/open/firedancer/npc/eq/r_hands",
		"file5"    : "/open/firedancer/npc/eq/r_belt",
		"amount7"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_leg",
		"file2"    : "/open/firedancer/npc/eq/r_armbands",
		"file7"    : "/open/firedancer/npc/eq/r_neck",
		"file6"    : "/open/firedancer/npc/eq/r_cape",
	]) );
	set( "owner", "del" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room306.c",
		"up"        : "/open/clan/ou-cloud-club/room/room311",
		"north"     : "/open/clan/ou-cloud-club/room/room307.c",
		"west"      : "/open/clan/ou-cloud-club/room/room308.c",
		"east"      : "/open/clan/ou-cloud-club/room/room313.c",
		"down"      : "/open/clan/ou-cloud-club/room/room314.c",
	]) );
	set( "build", 11802 );
	set( "light_up", 1 );
	set( "long", @LONG
  
    眼前是一座風景優美的牧場，除了可以遠眺綿延不絕的高
山，不遠處還有一座清澈見底的人工湖，這裡的牛牛就是在這
樣的環境下才能隻隻頭好壯壯，突然間有兩隻小牛跑到你腳邊
磨蹭，可愛的模樣讓人不禁發出會心一笑。
ˉ
LONG);
	setup();
	replace_program(ROOM);
}
