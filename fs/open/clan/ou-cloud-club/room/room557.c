inherit ROOM;
void create() {
	set( "short", "$HIY$蒼龍巢-防 1$NOR$" );
	set( "owner", "taa" );
	set( "object", ([
		"file1"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"file8"    : "/open/tendo/obj/chaosbelt",
		"file3"    : "/open/wu/npc/obj/armband",
		"file7"    : "/open/mogi/castle/obj/lochagem",
		"file9"    : "/open/wind-rain/obj/sun_red_cloth",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"amount2"  : 1,
		"file6"    : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"file10"   : "/open/wu/obj/figring",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10587 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room555",
	]) );
	set( "long", @LONG

    這是一間存放獅王防具及其它雜物的大房間，在獅穴中佔有很重要
的地位。房間中裝璜的非常漂亮，牆璧上一張蠻清楚的防具列表清單，
吸引了你的視線，上頭的ＰＯＰ字寫得很不錯。洶都十分的
乾淨。但因為是服物台的管理人員相當盡則，所以您存放的物品也都在
架上排列的非常整齊。

LONG);
	setup();
	replace_program(ROOM);
}
