// Room : /open/clan/ou-cloud-club/room/room72.c
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
		"amount4"  : 1,
		"amount10" : 500,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 14,
		"amount1"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/killer/headkill/obj/e_dag",
		"file2"    : "/open/killer/obj/s_pill",
		"file10"   : "/open/killer/obj/hate_knife",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10011 );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "up" : "/open/clan/ou-cloud-club/room/room73.c",
  "down" : "/open/clan/ou-cloud-club/room/room71",
]) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );
	setup();

	}
