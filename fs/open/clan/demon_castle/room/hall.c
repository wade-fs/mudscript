// Room : /open/clan/demon_castle/room/hall.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "惡魔城" );
	set( "build", 93 );
	set( "light_up", 1 );
	set( "no_transmit", 1 );
	set( "long", @LONG

    這裡是惡魔城的主大殿，一尊龐大的雕像塑立在你眼前，只見雕
像的雙眼隱約透露出邪惡的殺氣，八條魔龍攀附著雕像朝天而嘯，相
傳惡魔城是由武林第一邪魔 -- 傅劍寒一手創立的，其手下聚集一股
龐大的惡勢力令人聞之喪膽，所以惡魔城也被列為武林禁地，其幫主
傅劍寒更被喻為惡魔化身。

LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 4 */
		"up"        : "/open/clan/demon_castle/room/room5.c",
		"north"     : "/open/clan/demon_castle/room/room3.c",
		"west"      : "/open/clan/demon_castle/room/room2.c",
]) );
	setup();
	call_other( "/obj/board/demon_castle_b.c", "???" );

	}
