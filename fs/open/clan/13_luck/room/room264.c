inherit ROOM;
void create() {
	set( "short", "妖幻護膝房" );
	set( "object", ([
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room308",
		"south"     : "/open/clan/13_luck/room/room303.c",
	]) );
	set( "build", 10245 );
	set( "light_up", 1 );
	set( "long", @LONG

    此防具，為聞名無不嚇破膽的千年樹妖舞風揚身上所有的，此妖有
千年之功力，長年在長白山上修練，法術更是無人能敵，與他為敵只會
一肚子大便的狀態，尤其是虛弱，所以他的防具不是說有就有的，也要
看有沒有人敢去打為了那一件妖幻護膝。

LONG);
	setup();
	replace_program(ROOM);
}
