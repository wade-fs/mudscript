inherit ROOM;
void create() {
	set( "short", "『洛陽客棧』" );
	set( "owner", "mill" );
	set( "object", ([
		"amount9"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_head",
		"amount10" : 1,
		"file6"    : "/open/firedancer/npc/eq/r_cape",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_leg",
		"file10"   : "/open/firedancer/npc/eq/r_shield",
		"file9"    : "/open/firedancer/npc/eq/r_armbands",
		"file3"    : "/open/firedancer/npc/eq/r_hands",
		"amount4"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_belt",
		"file4"    : "/open/firedancer/npc/eq/r_finger",
		"amount2"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_cloth",
	]) );
	set( "build", 10077 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room474",
		"north"     : "/open/clan/13_luck/room/room464",
		"east"      : "/open/clan/13_luck/room/room465.c",
	]) );
	set( "long", @LONG
  
     你現在正站在洛陽城東邊的一家客棧裡﹐客棧的主人據說和襄陽城的
 明天客棧是同一位﹐如果你的福緣深厚的話﹐也許可以在這裡遇到他。除
 此之外﹐來自各地的旅人都喜歡聚集在這裡交換旅途上的見聞﹐你也可以
 在這裡打聽到許多有趣的消息。靠近門口的地方有一塊招牌(sign)。

LONG);
	setup();
	replace_program(ROOM);
}
