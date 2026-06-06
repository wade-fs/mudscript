inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$HIC$水色靈帶$NOR$" );
	set( "owner", "car" );
	set( "object", ([
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"amount10" : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 11377 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room96",
	]) );
	set( "long", @LONG
水色靈帶(water ribbon),水淵流所使用的靈帶,水光閃閃奪目,令人無法直視,
水淵流是位傑出的舞者,精通各種法術,尤其是玄冰結界和水月神鏡,玄冰結界
會將你的攻擊反彈回來並加倍損失,水月神鏡會提高數倍的防禦力,再加上水色
靈光會將你的enf減半,是五塔主中最難纏的角色,而打倒水淵流就可以得到水
色靈帶,據說是開啟聚靈道的重要道具

LONG);
	setup();
	replace_program(ROOM);
}
