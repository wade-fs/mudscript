inherit ROOM;
void create() {
	set( "short", "綠茶園前庭" );
	set( "owner", "biog" );
	set( "object", ([
		"file4"    : "/obj/gift/lingzhi",
		"amount8"  : 1,
		"amount6"  : 1,
		"amount10" : 17,
		"file1"    : "/obj/gift/hobowdan",
		"amount9"  : 1,
		"file8"    : "/obj/gift/bingtang",
		"file10"   : "/open/killer/obj/s_pill",
		"file5"    : "/open/capital/obj/gold_pill",
		"amount1"  : 1,
		"file6"    : "/open/gblade/obj/sa-head",
		"amount4"  : 1,
		"amount5"  : 1,
		"file9"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 13097 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room187.c",
		"west"      : "/open/clan/13_luck/room/room190",
		"out"       : "/open/clan/13_luck/room/room91.c",
		"south"     : "/open/clan/13_luck/room/room189.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡就是綠茶園的前庭，走在一條南北向的青石步道上，步道兩
旁種滿了許多的花，庭院的四周圍則被一排高大的松樹所包圍，
空氣中到處都充滿宜人的氣息，令人想逗留在此。  往南是通往
綠茶園的大廳，往東看去則給人一片霧濛濛的感覺，往西則是通
往綠茶園的側廳。 
LONG);
	setup();
	replace_program(ROOM);
}
