inherit ROOM;
void create() {
	set( "short", "gk eq-cloak" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "object", ([
		"amount6"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount1"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-cloak",
	]) );
	set( "build", 10521 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room95",
	]) );
	set( "long", @LONG

登臨送目，正故國晚秋，天氣初肅。 

千里澄江似練，翠峰如簇。

征帆去棹殘陽裏，背西風、酒旗斜矗。

彩舟雲淡、星河露起，畫圖難足。

念往昔、繁華競逐，嘆門外樓頭，悲恨相續。

千古憑高對此，漫嗟榮辱。

六朝舊事隨流水，但寒煙、衰草凝綠。

至今商女，時時猶唱，<後庭>遺曲


LONG);
	setup();
	replace_program(ROOM);
}
