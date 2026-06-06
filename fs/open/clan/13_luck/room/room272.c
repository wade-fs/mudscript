inherit ROOM;
void create() {
	set( "short", "妖幻披掮室" );
	set( "object", ([
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/ghost-hole/obj/fire-spirit",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"file9"    : "/open/ghost-hole/obj/fire-spirit",
		"amount9"  : 1,
		"amount6"  : 1,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room312",
		"south"     : "/open/clan/13_luck/room/room301.c",
	]) );
	set( "build", 11298 );
	set( "light_up", 1 );
	set( "long", @LONG

    此防具，為聞名無不嚇破膽的千年樹妖舞風揚身上所有的，此妖有
千年之功力，長年在長白山上修練，法術更是無人能敵，與他為敵只會
一肚子大便的狀態，尤其是虛弱，所以他的防具不是說有就有的，也要
看有沒有人敢去打為了那一件妖幻披掮。

LONG);
	setup();
	replace_program(ROOM);
}
