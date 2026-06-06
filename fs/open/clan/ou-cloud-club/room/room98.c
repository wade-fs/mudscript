// Room : /open/clan/ou-cloud-club/room/room98.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "傲雲山莊" );
	set( "short", "$HIW$惡魔城$HIR$地下水脈$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10028 );
	set( "light_up", 1 );
	set( "long", @LONG
這裡有幾處突起的地面坐落在水中,看來踩著這些地方也能
前進,慢慢走吧,由於溼度的關係,地面上可是長滿了青苔呢.可
小心點不要掉下去了呢,傳說惡魔城存在著能在水裡吐發火焰
的怪魚,若掉下去真的被逮著了那可就不好玩嘍~~~

LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room99.c",
  "west" : "/open/clan/ou-cloud-club/room/room44",
]) );
	set( "no_transmit", 1 );
	setup();

	}
