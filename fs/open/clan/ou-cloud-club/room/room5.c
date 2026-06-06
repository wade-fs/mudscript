// Room : /open/clan/ou-cloud-club/room/room5.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
		"west"      : "/open/clan/ou-cloud-club/room/room490.c",
		"up"        : "/open/clan/ou-cloud-club/room/room623",
		"north"     : "/open/clan/ou-cloud-club/room/room560.c",
		"south"     : "/open/clan/ou-cloud-club/room/room561.c",
		"east"      : "/open/clan/ou-cloud-club/room/room407.c",
]) );
	set( "long", @LONG

    這是一間存放獅王武器及其它雜物的大房間，在獅穴中佔有很重要
的地位。房間中裝璜的非常漂亮，牆璧上一張蠻清楚的武器列表清單，
吸引了你的視線，上頭的ＰＯＰ字寫得很不錯。洶都十分的
乾淨。但因為是服物台的管理人員相當盡則，所以您存放的物品也都在
架上排列的非常整齊。

LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "light_up", 1 );
	set( "short", "$MAG$龍王窟-武$NOR$" );
	set( "owner", "taa" );
	set( "build", 10308 );
	set( "object", ([
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/gsword/obj/dragon-sword",
		"file1"    : "/open/gsword/obj1/blosword",
		"amount1"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/obj/fon-sky-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount3"  : 1,
	]) );
	setup();

	}
