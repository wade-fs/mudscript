inherit ROOM;
void create() {
	set( "short", "朱雀堂" );
	set( "owner", "mad" );
	set( "object", ([
		"amount2"  : 1,
		"file7"    : "/open/tendo/obj/chaosbelt",
		"amount10" : 1,
		"amount8"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"amount9"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/daemon/class/fighter/armband",
		"amount3"  : 1,
		"file8"    : "/open/mogi/village/obj/mogi_ring",
		"amount1"  : 1,
		"file10"   : "/open/mogi/castle/obj/lochagem",
		"amount7"  : 1,
		"file9"    : "/open/mogi/castle/obj/seven5-dark-head",
		"file5"    : "/daemon/class/blademan/obj/shield",
		"amount4"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/daemon/class/blademan/obj/shield",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 19190 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room15",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在朱雀堂的室內不少人忙進忙出的工作，這裡是管十三吉祥的文書
中心，在這裡你可以找到有關十三吉祥的事件與名冊，敘述著它以前輝
煌的歷史和創立十三吉祥時前人的為艱，並將永傳下去與不滅絕有如鳳
凰一般，更希望能勉勵後人繼承先人的遺志。

LONG);
	setup();
	replace_program(ROOM);
}
