inherit ROOM;
void create() {
	set( "short", "美妃的臥室" );
	set( "object", ([
		"amount2"  : 1,
		"amount7"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/daemon/class/fighter/ywhand",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/obj/dark-soul-dagger",
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"file5"    : "/daemon/class/fighter/armband",
		"amount8"  : 1,
		"file2"    : "/open/gsword/obj/yuskirt",
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/prayer/obj/boris-cloth",
		"amount10" : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 12000 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room136",
	]) );
	set( "long", @LONG
這裡是空瓶子的夫人『美妃』的臥室，當你一走進這裡時你就感受
一種只有奇特女子才有的香味，那一種香味並不是很重很重的那種香味
而是一種自然的體香，因為人們又叫她為『香妃』。且又因為她是使用
刀的專家，所以人們又也叫他『絕魂刀姬』，他有一把上古名器，此刀
開鞘後一定要見血。這把刀就是『太皇刀─藍牙』而這把刀一定要美
妃才能使用的得心應手。這也難怪了，因為這把刀是有靈性的，只跟隨
她的主人，而它的主人就是美妃。

LONG);
	setup();
	replace_program(ROOM);
}
