// Room : /open/clan/ou-cloud-club/room/room99.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "傲雲山莊" );
	set( "short", "$HIW$惡魔城$HIR$地下水脈$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"file9"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
	]) );
	set( "build", 10016 );
	set( "light_up", 1 );
	set( "long", @LONG
這裡有幾處突起的地面坐落在水中,看來踩著這些地方也能
前進,慢慢走吧,由於溼度的關係,地面上可是長滿了青苔呢.可
小心點不要掉下去了呢,傳說惡魔城存在著能在水裡吐發火焰
的怪魚,若掉下去真的被魔物逮著了,那可就大擭嘍~~~
LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room100.c",
  "west" : "/open/clan/ou-cloud-club/room/room98",
]) );
	set( "no_transmit", 1 );
	setup();

	}
