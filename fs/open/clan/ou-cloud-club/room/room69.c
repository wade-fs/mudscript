// Room : /open/clan/ou-cloud-club/room/room69.c
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
		"file1"    : "/open/gsword/obj1/blosword",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/gsword/obj1/blosword",
		"file5"    : "/open/gsword/obj1/blosword",
		"amount4"  : 1,
		"file9"    : "/open/gsword/obj1/blosword",
		"amount3"  : 1,
		"file4"    : "/open/gsword/obj1/blosword",
		"file8"    : "/open/gsword/obj1/blosword",
		"amount6"  : 1,
		"amount10" : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/gsword/obj1/blosword",
	]) );
	set( "build", 10058 );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "up" : "/open/clan/ou-cloud-club/room/room70.c",
  "down" : "/open/clan/ou-cloud-club/room/room68",
]) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );
	setup();

	}
