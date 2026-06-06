inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$內$BBLU$力$BMAG$房$BCYN$1$NOR$" );
	set( "owner", "agilent" );
	set( "object", ([
		"file10"   : "/open/wind-rain/obj/sun_red_cloth",
		"amount10" : 1,
		"file9"    : "/open/mogi/castle/obj/lochagem",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount7"  : 1,
		"amount3"  : 1,
		"file5"    : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/tendo/obj/chaosbelt",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount2"  : 1,
		"file7"    : "/open/wu/obj/figring",
		"amount6"  : 1,
		"file4"    : "/open/wu/obj/armband",
		"amount9"  : 1,
	]) );
	set( "build", 10102 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room98",
		"north"     : "/open/clan/time-limit/room/room2",
	]) );
	set( "long", @LONG
夕霞紅紗(Sun_red_cloth) add 10        羅剎女飾(gem) add 10
陽炎臂環 (Sun Fire Armband) add 10    狂龍翔天破(Crazy dragon) add 10
妖幻披掮(ghost cloak) add 10          妖幻頭帶(ghost helmet) add 10
妖幻護膝(ghost legging) add 10        混沌腰帶(chaos belt) add 8
魔法盾(magic shield) add 5            幸運草環(lucky grasslink) add 5

LONG);
	setup();
	replace_program(ROOM);
}
