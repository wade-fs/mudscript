// Room : /open/clan/ou-cloud-club/room/room64.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$時計ソ廊$NOR$" );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 3 */
  "east" : "/open/clan/ou-cloud-club/room/room66.c",
  "west" : "/open/clan/ou-cloud-club/room/room65.c",
  "eastdown" : "/open/clan/ou-cloud-club/room/room61",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
這裡的通路程東西走向,然而東面很明顯的可以看到一面
大峭壁,而西面則是佈滿了零稀幾座泛黃的磚牆.牆上掛著一把
巨劍,劍的四周則放射狀排列的掛著斧,刀,戢,棍,槍...等各式
兵刃,妨拂釋放出萬般兵器劍為皇的訊息,只是,當你踏足進入
劍的十尺之內時,諸般兵器繞著劍緩緩的轉動了起來...
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
