inherit ROOM;
void create() {
	set( "short", "$HIY$蒼龍巢-防 2$NOR$" );
	set( "object", ([
		"file5"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/capital/guard/gring",
		"amount4"  : 1,
		"file3"    : "/open/wu/obj/armband",
		"amount2"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
	]) );
	set( "owner", "taa" );
	set( "build", 10041 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room555",
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
