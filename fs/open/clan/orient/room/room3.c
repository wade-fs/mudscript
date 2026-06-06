inherit ROOM;
void create() {
	set( "short", "$HIW$『幫主室』$HIC$落雨飄飄懸思憶$NOR$" );
	set( "owner", "borkiller" );
	set( "object", ([
		"file10"   : "/open/killer/obj/atman_pill",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"file7"    : "/open/fire-hole/obj/b-pill",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 2,
		"amount10" : 1470,
		"amount5"  : 122,
		"amount3"  : 6,
		"amount2"  : 101,
		"file1"    : "/open/mon/obj/thousand-nectar",
		"amount4"  : 89679,
		"amount9"  : 119,
		"file9"    : "/open/mon/obj/mon-pill",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 2,
		"amount8"  : 1,
		"amount6"  : 292,
		"file4"    : "/open/killer/obj/bellstar",
	]) );
	set( "light_up", 1 );
	set( "build", 10013 );
	set( "exits", ([
		"south"     : "/open/clan/orient/room/hall",
		"north"     : "/open/clan/orient/room/room27.c",
	]) );
	set( "long", @LONG

    這庭子約五六米大﹐六根深紅色的柱子朝天而立﹐形成了一個六角形
庭子中央放置一個方形的石几﹐和三四把石椅。椅上大理石為雲南基石﹐
不但看起來態若雲霧﹐宛如飄逸﹐石几上的雕飾更為深刻﹐不但有錦繡山
河﹐更有群山萬壑﹐頗有澎湃之氣勢。
    此時雲霧四起﹐庭外落雨紛飛﹐飄落的雨水滴賤在庭棚上﹐聲聲刺入
孤獨人的心中﹐雨聲時而低鳴﹐時而奔落鴻音﹐如慕如訴﹐有如泣如呼﹐
不禁令人回首過往﹐絲絲涼意襲上心頭。

LONG);
	setup();
	replace_program(ROOM);
}
