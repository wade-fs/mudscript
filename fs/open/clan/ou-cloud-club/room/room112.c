// Room : /open/clan/ou-cloud-club/room/room112.c
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
	set( "short", "$RED$惡魔城$NOR$煉氣房" );
	set( "object", ([
		"amount9"  : 1,
		"amount10" : 1,
		"file10"   : "/open/mogi/castle/obj/lochagem",
		"file2"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/wu/npc/obj/armband",
		"amount7"  : 1,
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"amount5"  : 1,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"file8"    : "/open/gsword/obj/may_ring",
		"amount4"  : 1,
		"file1"    : "/daemon/class/fighter/figring",
		"file7"    : "/open/tendo/obj/chaosbelt",
		"amount8"  : 1,
	]) );
	set( "owner", "bbsboss" );
	set( "light_up", 1 );
	set( "build", 10158 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room127.c",
  "west" : "/open/clan/ou-cloud-club/room/room111",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
