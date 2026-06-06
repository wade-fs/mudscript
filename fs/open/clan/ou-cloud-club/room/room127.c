// Room : /open/clan/ou-cloud-club/room/room127.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
你走在水中幾處較為高聳的土丘上,在這裡你發現了不少
青蛙跳來跳去,看來在這邪惡的城堡之內,還是會有一些比較
正常的生物的,然而即便如此,這些兩棲類的小生命卻似乎對
你存著些許敵意,或許是你無形中打擾了他們平靜的生活吧!
LONG);
	set( "cmkroom", 1 );
	set( "short", "$HIR$惡魔城$HIW$地下水脈$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"amount9"  : 20,
		"amount8"  : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"amount2"  : 1,
		"file9"    : "/open/mon/obj/thousand-nectar",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/firedancer/npc/eq/r_boots",
		"amount6"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/daemon/class/blademan/obj/gold-blade",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_pants",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/firedancer/npc/eq/r_hands",
		"amount4"  : 1,
	]) );
	set( "build", 10004 );
	set( "light_up", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room128.c",
  "west" : "/open/clan/ou-cloud-club/room/room112",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
