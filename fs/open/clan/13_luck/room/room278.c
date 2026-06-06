inherit ROOM;
void create() {
	set( "short", "幻紋妖爪房" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file4"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file7"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file1"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/obj/fon-sky-sword",
	]) );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room271",
	]) );
	set( "build", 10431 );
	set( "light_up", 1 );
	set( "long", @LONG

    此防具，為聞名無不嚇破膽的千年樹妖舞風揚身上所有的，此妖有
千年之功力，長年在長白山上修練，法術更是無人能敵，與他為敵只會
一肚子大便的狀態，尤其是虛弱，所以他的防具不是說有就有的，也要
看有沒有人敢去打，為了那一件幻紋妖爪。

LONG);
	setup();
	replace_program(ROOM);
}
