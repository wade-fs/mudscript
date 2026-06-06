// Room : /open/clan/ou-cloud-club/room/room71.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
一條纏如盤蛇的道路，此去延綿不絕，兩側僅足　　　　　
一尺寬，長不見底，兩旁毫無著力點，故此處易守難　　　　　
攻，進退兩難，若在此處遭到攻擊，必前面忌虎，難　　　　　
以招架‧‧‧．　　　　　
　　　　　
LONG);
	set( "short", "$HIY$天山$NOR$徑" );
	set( "object", ([
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10011 );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "up" : "/open/clan/ou-cloud-club/room/room72.c",
  "down" : "/open/clan/ou-cloud-club/room/room70",
]) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );
	setup();

	}
