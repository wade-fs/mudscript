inherit ROOM;
void create() {
	set( "short", "卸甲亭" );
	set( "owner", "gever" );
	set( "object", ([
		"amount10" : 1,
		"file5"    : "/open/tendo/obj/chaosbelt",
		"amount2"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/wu/obj/figring",
		"amount3"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"amount5"  : 1,
		"file6"    : "/daemon/class/blademan/obj/shield",
		"file1"    : "/open/wind-rain/obj/sun_red_cloth",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/mogi/castle/obj/lochagem",
		"amount8"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/wu/obj/armband",
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
	]) );
	set( "build", 10082 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room693",
		"out"       : "/open/clan/13_luck/room/room589.c",
		"east"      : "/open/clan/13_luck/room/room692.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
穿越刀塚後,眼前忽然豁然開朗起來.只見流水潺潺,樹影掩映
觸目所及皆是一片和平安詳的景象看到這樣的景象,你不禁楞
楞地看得痴了.再往樹下望去,只見一別緻的小亭,紅瓦白柱,亭
下立著不應有恨的身影只作輕裝打扮,抬頭一看猛然發現三個
大字--
                『卸甲亭』
LONG);
	setup();
	replace_program(ROOM);
}
