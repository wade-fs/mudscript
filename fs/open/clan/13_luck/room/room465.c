inherit ROOM;
void create() {
	set( "short", "『洛陽客棧後院』" );
	set( "owner", "mill" );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount8"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file1"    : "/daemon/class/blademan/obj/gold-blade",
		"amount4"  : 1,
		"amount10" : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/capital/obj/blade2",
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file9"    : "/open/quests/snake/npc/obj/snake_gem",
		"file7"    : "/open/magic-manor/obj/maun-shadow-blade",
	]) );
	set( "build", 10032 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room466",
	]) );
	set( "long", @LONG
  
     你現在正站在洛陽客棧後院裡﹐客棧的主人據說和襄陽城的明天客
 棧是同一位﹐如果你的福緣深厚的話﹐也許可以在這裡遇到他。除此之
 外﹐來自各地的旅人都喜歡聚集在這裡交換旅途上的見聞﹐你也可以在
 這裡打聽到許多有趣的消息,這裡有個髒蓋子(cover)。

LONG);
	setup();
	replace_program(ROOM);
}
