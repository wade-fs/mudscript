inherit ROOM;
void create() {
	set( "short", "$HIW$虎王窟-道 1$NOR$" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room316",
	]) );
	set( "owner", "taa" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10973 );
	set( "long", @LONG

    這是一間存放獅王道具及其它雜物的大房間，在獅穴中佔有很重要
的地位。房間中裝璜的非常漂亮，牆璧上一張蠻清楚的道具列表清單，
吸引了你的視線，上頭的ＰＯＰ字寫得很不錯。洶都十分的
乾淨。但因為是服物台的管理人員相當盡則，所以您存放的物品也都在
架上排列的非常整齊。

LONG);
	setup();
	replace_program(ROOM);
}
