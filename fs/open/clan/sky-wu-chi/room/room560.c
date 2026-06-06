inherit ROOM;
void create() {
	set( "short", "ddt雜物間-2" );
	set( "owner", "cong" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 11246 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room561",
		"north"     : "/open/clan/sky-wu-chi/room/room562",
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
