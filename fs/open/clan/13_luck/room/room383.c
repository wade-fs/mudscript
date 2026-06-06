inherit ROOM;
void create() {
	set( "short", "十三戰堂正殿" );
	set( "object", ([
		"file7"    : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"amount9"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10062 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room380",
		"west"      : "/open/clan/13_luck/room/room381.c",
		"east"      : "/open/clan/13_luck/room/room382.c",
		"north"     : "/open/clan/13_luck/room/room384.c",
	]) );
	set( "long", @LONG

    十三戰堂的正殿與其他各堂並無太大的差別，只見大殿中央佇立著一
位年近六旬的老人，這人雖老但從其儀態及他所散發出來的氣息便知他並
非普通的小人物，也許你已經猜到了，他就是十三戰堂的堂主『戰十三』
，他身旁有許多弟子正在詢問他有關戰略上的問題，而他正細心的教導著
戰堂弟子們。

LONG);
	setup();
	replace_program(ROOM);
}
