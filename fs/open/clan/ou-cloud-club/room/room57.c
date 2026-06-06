// Room : /open/clan/ou-cloud-club/room/room57.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$時計ソ廊$NOR$" );
	set( "build", 10545 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 5 */
  "eastup" : "/open/clan/ou-cloud-club/room/room62.c",
  "east" : "/open/clan/ou-cloud-club/room/room58.c",
  "west" : "/open/clan/ou-cloud-club/room/room56",
  "westup" : "/open/clan/ou-cloud-club/room/room61.c",
  "up" : "/open/clan/ou-cloud-club/room/room63.c",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
面前突然出現了一座大鍾,你感到腳底下的石板似乎不甚
平穩,再望向天花板,才發現上面有著三條可以徒手攀登而上
的狹小隧道,中間的一條筆直向上而去,似乎是個天井,西邊
的一條則有時開有時關,至於東邊的,有時乍看之下是開的,
一回神之後卻是關的,足見設計的人一定頗費心思在機關控制
之上.
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
