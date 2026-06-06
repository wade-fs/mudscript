inherit ROOM;
void create() {
	set( "short", "壤外定疆樓" );
	set( "object", ([
		"amount3"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file10"   : "/open/mogi/castle/obj/lochagem",
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 14901 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room162.c",
		"north"     : "/open/clan/13_luck/room/room180.c",
	]) );
	set( "long", @LONG

    十三吉祥成立之初，出現兩為奇人一為寒紫星一為龍，在十三吉
祥成立之初，百廢待興，當時就由此兩人幫著十三吉祥在外打響名聲
，擴大幫派勢力，成就了現在的十三吉祥，但此兩人在功成後就身退
了，閒雲野鶴不管幫務，對於他們的成就將是幫眾將永記於心。 

LONG);
	setup();
	replace_program(ROOM);
}
