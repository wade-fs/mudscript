// Room : /open/clan/ou-cloud-club/room/room74.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
你費盡了千辛萬苦，終於來到這裡，正當你在閉息養神之時，你赫然　　
發現，往上的道路更是崎嶇彎折，而且似乎暗藏有五行八卦之陣，令眼前　　
的路更加詭譎異誕，步步難行，接下來的路就得看你自己的造化了‧‧‧　　
　　　　　
LONG);
	set( "short", "$HIY$天山$NOR$山腰" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/ping/questsfan/obj/diamond_legging",
		"amount2"  : 1,
		"file5"    : "/open/ping/questsfan/obj/diamond_skirt",
		"file6"    : "/open/ping/questsfan/obj/diamond_belt",
		"amount5"  : 1,
		"file4"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"file10"   : "/open/ping/obj/cloud_fan",
		"file3"    : "/open/ping/questsfan/obj/diamond_armor",
		"file9"    : "/open/ping/questsfan/obj/diamond_hands",
		"amount7"  : 1,
		"file1"    : "/open/ping/questsfan/obj/stone",
		"amount3"  : 1,
		"file8"    : "/open/ping/questsfan/obj/diamond_boots",
		"amount10" : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount1"  : 1,
	]) );
	set( "build", 10023 );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "up" : "/open/clan/ou-cloud-club/room/room75.c",
  "down" : "/open/clan/ou-cloud-club/room/room73",
]) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );
	setup();

	}
