inherit ROOM;
void create() {
	set( "short", "妖幻裝備室" );
	set( "owner", "son" );
	set( "object", ([
		"file5"    : "/daemon/class/blademan/obj/gstone",
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/daemon/class/blademan/obj/hstone",
		"file10"   : "/obj/gift/xiandan",
		"amount2"  : 1,
		"file9"    : "/open/gsword/obj1/bpball",
		"amount3"  : 1,
		"file6"    : "/daemon/class/blademan/obj/wastone",
		"file1"    : "/daemon/class/blademan/obj/estone",
		"amount10" : 1,
		"file7"    : "/daemon/class/blademan/obj/fstone",
		"file8"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/daemon/class/blademan/obj/wstone",
		"amount9"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10488 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room70",
	]) );
	set( "long", @LONG

    昔日小南前往長白山時，發現山腰處陰氣重重，有一股強烈妖氣
和殺氣，走到樹林的深處發現竟然有一個幻化成人形的樹妖(舞風揚)
交戰數回後，感覺此樹妖已有千百年的功力了，逼不得已小南只好運
起畢生最強功力(第十重天)，不知交手過千百回後，終於降服了樹妖
而小南也身重重傷，在四。五年之內才有可能恢復內力。 


妳發覺黃銅色的迷霧圍繞正在妳四周


LONG);
	setup();
	replace_program(ROOM);
}
