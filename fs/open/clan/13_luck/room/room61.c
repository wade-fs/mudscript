inherit ROOM;
void create() {
	set( "short", "ζ紫星堂ζ" );
	set( "owner", "papt" );
	set( "object", ([
		"amount2"  : 1,
		"amount7"  : 1,
		"amount9"  : 3,
		"file4"    : "/open/doctor/pill/f_pill",
		"file8"    : "/open/ping/obj/gold_hand",
		"amount4"  : 10,
		"amount8"  : 1,
		"file5"    : "/open/killer/obj/k_ring",
		"file9"    : "/open/ping/obj/poison_pill",
		"amount5"  : 1,
		"file2"    : "/open/main/obj/shiblade",
		"file7"    : "/open/ping/obj/chilin_legging",
	]) );
	set( "build", 10570 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room54.c",
		"enter"     : "/open/clan/13_luck/room/room62",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    走進此地隱約有一股無名的殺氣緊盯著妳，四周的空氣有如寒冰
結霜般的令妳透不過氣來，寒風颼颼的吹，妳的心跳亦隨著加速跳動
眼前一位神秘之人盤坐於七彩靈石之上吸收著大地精華，透露出一種
詭異的感覺，看來此處不是你久留之地，還是趁早離開為妙。

LONG);
	setup();
	replace_program(ROOM);
}
