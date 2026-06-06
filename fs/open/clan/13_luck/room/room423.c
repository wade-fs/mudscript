inherit ROOM;
void create() {
	set( "short", "冥想室" );
	set( "owner", "zeros" );
	set( "object", ([
		"amount9"  : 550,
		"file7"    : "/open/fire-hole/obj/k-pill",
		"file10"   : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount5"  : 430,
		"amount10" : 40,
		"file2"    : "/open/ping/obj/poison_pill",
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 98,
		"file3"    : "/open/fire-hole/obj/y-pill",
		"file4"    : "/open/mon/obj/mon-pill",
		"amount6"  : 1309,
		"amount7"  : 240,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 265,
		"amount4"  : 90,
		"amount1"  : 219,
		"file8"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount2"  : 347,
	]) );
	set( "build", 10091 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room119",
	]) );
	set( "long", @LONG
這裡是讓劍如冰冥想的地方，由於他持續的冥想的終於突破了大限，
達到學究天人之境界，如果你也想達成學究天人，可以考慮是否來這
裡與她一起冥想，一起突破學究天人的境界，一起探討無盡深遠的武
學奧妙之處，期望可以達到武學的功力無限深遠。
LONG);
	setup();
	replace_program(ROOM);
}
