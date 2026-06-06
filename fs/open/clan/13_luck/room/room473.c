inherit ROOM;
void create() {
	set( "short", "『關帝廟』" );
	set( "owner", "mill" );
	set( "object", ([
		"file3"    : "/open/firedancer/npc/eq/r_neck",
		"amount2"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_armbands",
		"file8"    : "/open/firedancer/npc/eq/r_belt",
		"amount3"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_cape",
		"file1"    : "/open/firedancer/npc/eq/r_leg",
		"amount6"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"file2"    : "/open/firedancer/npc/eq/r_head",
		"amount8"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_finger",
		"file5"    : "/open/firedancer/npc/eq/r_cloth",
		"file10"   : "/open/firedancer/npc/eq/r_shield",
	]) );
	set( "build", 11455 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room474",
	]) );
	set( "long", @LONG

     這是一間十分老舊的關帝廟﹐在你面前的神桌上供奉著一尊紅臉的關
 聖帝君﹐廟雖老舊﹐但是神案四周已被香火薰成烏黑的顏色﹐顯示這裡必
 定相當受到信徒的敬仰,仔細一看大廳的神案上還放著一些書(book),似乎
 有些特別。

LONG);
	setup();
	replace_program(ROOM);
}
