inherit ROOM;
void create() {
	set( "short", "種子庫藏" );
	set( "owner", "biom" );
	set( "object", ([
		"amount1"  : 305,
		"amount4"  : 207,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 1,
		"file4"    : "/open/ping/obj/poison_pill",
		"file6"    : "/open/fire-hole/obj/g-pill",
		"amount6"  : 311,
		"file2"    : "/open/mon/obj/mon-pill",
		"file5"    : "/open/fire-hole/obj/k-pill",
		"amount7"  : 112,
		"amount2"  : 253,
		"file8"    : "/obj/gift/xiandan",
		"amount10" : 68,
		"amount3"  : 60,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/open/mon/obj/thousand-nectar",
		"amount9"  : 99,
		"amount5"  : 133,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file9"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room73.c",
		"south"     : "/open/clan/13_luck/room/room120",
		"west"      : "/open/clan/13_luck/room/room671.c",
		"east"      : "/open/clan/13_luck/room/room56.c",
	]) );
	set( "build", 11232 );
	set( "light_up", 1 );
	set( "long", @LONG
來到此..看到眾多的靶場..一定又來到acomidy 的練習箭法的地方..
有75公尺靶場..175靶場..跟300靶場..最後還有1500公尺的描準射擊..
準備想發明一些新絕招..等待exp 300one的到來..
也期待偉大的巫師能給射手一些新招式..所以我一直沒有去解更高階的靈氣
怕以後會有鳳凰之氣的出現..addoil
LONG);
	setup();
	replace_program(ROOM);
}
