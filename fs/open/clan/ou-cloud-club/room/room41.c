// Room : /open/clan/ou-cloud-club/room/room41.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$入口$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/water-ball",
		"amount2"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/obj/water-ball",
		"file3"    : "/open/magic-manor/obj/soil-ball",
	]) );
	set( "owner", "bbsboss" );
	set( "build", 10005 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
在這裡你看到幾副巨大的鐵鍊,栓著幾頭魁武得有如大象般的生物,
似狼似犬,到底是狼還是犬已不容你細想,因為你瞥見其中幾條生鏽的古
老鐵鍊好像隨時會被這些正向你咆嘯的兇猛生物扯斷,更當你見到牠們
面前的一堆白骨時,不離則死的的訊息再腦海中一閃而過,快離開吧!!
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"up"        : "/open/clan/ou-cloud-club/room/room60",
		"east"      : "/open/clan/ou-cloud-club/room/room42.c",
		"west"      : "/open/clan/ou-cloud-club/room/room40.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
