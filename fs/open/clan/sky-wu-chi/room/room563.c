inherit ROOM;
void create() {
	set( "short", "$HIG$妮文絲湖$NOR$-2" );
	set( "owner", "coling" );
	set( "object", ([
		"amount1"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"file1"    : "/open/killer/obj/k_ring",
		"amount4"  : 1,
	]) );
	set( "build", 10002 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room507",
	]) );
	set( "long", @LONG
平靜且毫無漣漪的水面，加上偶爾探出頭到水面的魚。和幾隻在
水面上覓食的水鳥。妮文絲湖美得就像一幅不加框的畫。如玻璃一般
透明的水讓你可以一眼看到水底悠游的魚兒及其他生物。偶爾一陣風
吹過，泛起的漣漪加上光線的照射，那波光漣漪的景色讓人覺得渾身
舒暢。

LONG);
	setup();
	replace_program(ROOM);
}
