// Room : /open/clan/ou-cloud-club/room/room56.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$時計ソ廊$NOR$" );
	set( "build", 10031 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room57.c",
  "west" : "/open/clan/ou-cloud-club/room/room55",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
滴答滴答的聲音到處都是,你慄然驚見牆上掛了成千上百
各式各樣華麗的古老時鐘,更令人頭皮發麻的,是它們每一座鍾,
都分秒不差的指著相同的時刻,這樣龐大的一堆古老機械,不知
道為什麼會出現在渾沌的惡魔城裡,永生不死的魔物也會在乎
些許時光的流逝嗎...
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
