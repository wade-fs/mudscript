inherit ROOM;
void create() {
	set( "short", "ddt雜物間-4" );
	set( "owner", "cong" );
	set( "object", ([
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10676 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room614",
		"south"     : "/open/clan/sky-wu-chi/room/room562.c",
	]) );
	set( "light_up", 1 );
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
