inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$HIY$金色靈刀$NOR$" );
	set( "owner", "car" );
	set( "object", ([
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount5"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10011 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room92",
		"north"     : "/open/clan/time-limit/room/room95.c",
		"east"      : "/open/clan/time-limit/room/room94.c",
		"down"      : "/open/clan/time-limit/room/room97",
		"south"     : "/open/clan/time-limit/room/room93.c",
	]) );
	set( "long", @LONG
金色靈刀(golden blade),金極飄所使用的寶刀,金光閃閃的,令人無法直視,
金極飄是金刀的能人,一旦動手,就會立刻使出無影狂刀斬,還有金色靈光會
定人,並不容易對付,而且塔頂無路可逃,必須抱著必死的決心戰鬥,而打倒金
極飄就可以得到金色靈刀,據說是開啟聚靈道的重要道具

LONG);
	setup();
	replace_program(ROOM);
}
