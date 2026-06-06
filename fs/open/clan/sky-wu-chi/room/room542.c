inherit ROOM;
void create() {
	set( "short", "$HIG$妮文絲湖$NOR$-1" );
	set( "owner", "coling" );
	set( "object", ([
		"amount6"  : 34,
		"file6"    : "/open/fire-hole/obj/w-pill",
		"amount5"  : 96,
		"file8"    : "/open/fire-hole/obj/b-pill",
		"amount3"  : 44,
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount8"  : 9,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 51,
		"amount2"  : 100,
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file1"    : "/open/mon/obj/mon-pill",
		"amount1"  : 313,
		"file2"    : "/open/mogi/castle/obj/ninepill",
	]) );
	set( "light_up", 1 );
	set( "build", 10010 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room507",
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
