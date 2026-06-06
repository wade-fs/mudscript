// Room : /open/clan/ou-cloud-club/room/room103.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
你感覺到水面下似乎有點古怪,低頭往水裡一看,赫然發現
已看不見水底了,心理升起一股好奇心,或許在這下面有著什麼
寶物或機關也不一定,正所謂不入虎穴,焉得虎子,危險的地方,
也就是藏有寶物的地方,要下去一睹究竟嗎?
LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "short", "$HIW$惡魔城$HIR$地下水脈$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"file5"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
	]) );
	set( "build", 10005 );
	set( "light_up", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/ou-cloud-club/room/room104.c",
		"west"      : "/open/clan/ou-cloud-club/room/room100",
		"down"      : "/open/clan/ou-cloud-club/room/room102",
]) );
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	setup();

	}
