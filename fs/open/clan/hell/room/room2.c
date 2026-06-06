inherit ROOM;
void create() {
	set( "short", "$HIW$奈何橋尾$NOR$" );
	set( "object", ([
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file10"   : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount10" : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 14261 );
set( "exits", ([        
		"north"     : "/open/clan/hell/room/room13.c",
		"south"     : "/open/clan/hell/room/room3.c",
		"west"      : "/open/clan/hell/room/room95.c",
	]) );
	set( "long", @LONG
這裡已經是奈何橋的橋尾了，再往前走就要進鬼門關了，鬼門關前排
了好長的隊伍，隊伍裡大致上有三種人，一種是魂魄出竅，來地府觀光的
，另外一種就是陽壽已盡，而被鉤魂使者帶過來的，最後一種，就是像你
這種孤魂野鬼，死後沒地方去，只好來地府報到的。

  黑無常(Black gargoyle)
LONG);
	setup();
	replace_program(ROOM);
}
