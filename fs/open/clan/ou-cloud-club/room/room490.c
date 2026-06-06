inherit ROOM;
void create() {
	set( "short", "$MAG$龍王窟-武 4$NOR$" );
	set( "owner", "taa" );
	set( "object", ([
		"amount7"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
	]) );
	set( "build", 10275 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room5.c",
	]) );
	set( "long", @LONG

    這是一間存放獅王武器及其它雜物的大房間，在獅穴中佔有很重要
的地位。房間中裝璜的非常漂亮，牆璧上一張蠻清楚的武器列表清單，
吸引了你的視線，上頭的ＰＯＰ字寫得很不錯。洶都十分的
乾淨。但因為是服物台的管理人員相當盡則，所以您存放的物品也都在
架上排列的非常整齊。

LONG);
	setup();
	replace_program(ROOM);
}
