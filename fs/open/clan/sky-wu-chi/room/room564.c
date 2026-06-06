inherit ROOM;
void create() {
	set( "short", "$HIG$妮文絲湖$NOR$-3" );
	set( "object", ([
		"amount3"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "build", 3413 );
	set( "owner", "coling" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room507",
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
