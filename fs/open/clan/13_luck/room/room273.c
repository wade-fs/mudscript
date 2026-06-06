inherit ROOM;
void create() {
	set( "short", "妖幻頭帶室" );
	set( "object", ([
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room311",
		"south"     : "/open/clan/13_luck/room/room306.c",
	]) );
	set( "build", 10275 );
	set( "light_up", 1 );
	set( "long", @LONG

    此防具，為聞名無不嚇破膽的千年樹妖舞風揚身上所有的，此妖有
千年之功力，長年在長白山上修練，法術更是無人能敵，與他為敵只會
一肚子大便的狀態，尤其是虛弱，所以他的防具不是說有就有的，也要
看有沒有人敢去打為了那一件妖幻頭帶。

LONG);
	setup();
	replace_program(ROOM);
}
