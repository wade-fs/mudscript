// Room : /open/clan/ou-cloud-club/room/room104.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
游啊游的,發現水面上有幾片木板飄著,看來這不久前這附
近應該有人來過,不過既然還沒看到,還是專心游吧!!在這種地
方溺水可不是好玩的,而腳底下最好也多留意些,說不定深水下
另有洞天,更不能對水中可能發生的狀況掉以輕心.
LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "short", "$HIW$惡魔城$HIR$地下水脈$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount6"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/magic-manor/obj/water-ball",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
	]) );
	set( "build", 10004 );
	set( "light_up", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room105.c",
  "west" : "/open/clan/ou-cloud-club/room/room103",
]) );
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	setup();

	}
