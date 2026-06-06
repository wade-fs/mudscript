inherit ROOM;
void create() {
	set( "short", "dancer 贈 yaoblade" );
	set( "owner", "dfyw" );
	set( "object", ([
		"amount4"  : 300,
		"amount7"  : 100,
		"file2"    : "/open/doctor/pill/human_pill",
		"file7"    : "/open/doctor/pill/sky_pill",
		"file4"    : "/open/doctor/pill/gnd_pill",
		"amount6"  : 100,
		"amount8"  : 1,
		"file5"    : "/open/doctor/pill/sky_pill",
		"amount3"  : 200,
		"file6"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/doctor/pill/sky_pill",
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount2"  : 692,
		"amount5"  : 200,
	]) );
	set( "build", 10203 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room443.c",
		"out"       : "/open/clan/13_luck/room/room196.c",
		"jump"      : "/open/clan/13_luck/room/room548",
		"down"      : "/open/clan/13_luck/room/room440",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

邪魔轉生妖刀皇    魔兵出鞘嘯九幽    魔龍吞天碎九霄    妖犯乾坤亂紅塵
橫空越世葬崑崙    撕神裂佛絕萬宗    一心一意欲稱王    王者之路多阻擾
蒼天嫉妒催舞神    獨斷俠行救紅塵    孤傷感寂鐵鑄心    誓滅妖刀無遺願
斗轉星移逆穹蒼    九重宿命起風雲    劍人合一臻天劍    火鳳翱翔破刀魂

LONG);
	setup();
	replace_program(ROOM);
}
