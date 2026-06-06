inherit ROOM;
void create() {
	set( "short", "避世居" );
	set( "owner", "gever" );
	set( "object", ([
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 1,
		"amount10" : 13,
		"amount5"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/fire-hole/obj/w-pill",
		"file7"    : "/daemon/class/blademan/obj/shield",
		"file10"   : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/ping/obj/gold_hand",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"file6"    : "/open/wu/npc/obj/armband",
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 15,
		"amount7"  : 1,
		"file1"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "outdoors", "/open/clan/13_luck" );
	set( "build", 10102 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room691",
	]) );
	set( "long", @LONG
避世居從棄刀塚往西直去，不應有恨隱居之處據說就在此，
眼看眼前蒼茫，路似乎是走不盡漫漫長路，你心中不禁想問候不
應有恨家祖宗十八代，就在你難忍腳下趕路的酸痛感之時，忽然
一座小茅盧映入你眼簾，是啦！此地就是不應有恨俠隱之處

                ξ避世居ξ
LONG);
	setup();
	replace_program(ROOM);
}
