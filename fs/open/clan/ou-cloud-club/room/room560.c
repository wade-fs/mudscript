inherit ROOM;
void create() {
	set( "short", "$MAG$龍王窟-武 1$NOR$" );
	set( "owner", "taa" );
	set( "object", ([
		"amount4"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount10" : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "light_up", 1 );
	set( "build", 10216 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room5",
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
