inherit ROOM;
void create() {
	set( "short", "ddt雜物間-1" );
	set( "owner", "cong" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"file6"    : "/open/magic-manor/obj/master_snake_head",
	]) );
	set( "build", 12039 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room543.c",
		"north"     : "/open/clan/sky-wu-chi/room/room560.c",
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
