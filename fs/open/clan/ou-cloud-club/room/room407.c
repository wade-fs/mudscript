inherit ROOM;
void create() {
	set( "short", "$MAG$龍王窟-武 2$NOR$" );
	set( "owner", "taa" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/tendo/obj/chaosbelt",
		"amount2"  : 1,
		"file5"    : "/open/ping/obj/ring-2",
		"amount10" : 1,
		"amount4"  : 1,
		"file3"    : "/daemon/class/blademan/obj/shield",
		"file10"   : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount5"  : 1,
		"file2"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "build", 10256 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room5.c",
	]) );
	set( "light_up", 1 );
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
