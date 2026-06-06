// Room : /open/clan/ou-cloud-club/room/room66.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$時計ソ廊$NOR$" );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "west" : "/open/clan/ou-cloud-club/room/room64",
  "up" : "/open/clan/ou-cloud-club/room/room67.c",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
這面大峭壁坑坑洞洞的,很明顯的曾有人從這裡攀牆而上,
然而,如此高聳陡直的一面牆,若非身負絕頂輕功無法辦到,
只要一個不小心失足跌下,便會像面前一副副殘缺的骸骨般,
摔得四分五裂,身首異處,有勇氣嘗試爬上去看看嗎!?
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
