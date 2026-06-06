inherit ROOM;
void create() {
	set( "short", "$HIW$虎王窟-道$NOR$" );
	set( "owner", "taa" );
	set( "object", ([
		"file10"   : "/open/gblade/obj/sa-head",
		"amount4"  : 2,
		"file8"    : "/open/wu/npc/obj/armband",
		"file6"    : "/open/common/obj/liz_meat",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file9"    : "/open/common/obj/liz_meat",
		"amount1"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/common/obj/liz_meat",
		"amount6"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 10037 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room520.c",
		"up"        : "/open/clan/ou-cloud-club/room/room622",
		"south"     : "/open/clan/ou-cloud-club/room/room522.c",
		"north"     : "/open/clan/ou-cloud-club/room/room451.c",
		"east"      : "/open/clan/ou-cloud-club/room/room521.c",
	]) );
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
