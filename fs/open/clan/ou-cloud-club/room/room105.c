// Room : /open/clan/ou-cloud-club/room/room105.c
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
	set( "object", ([
		"amount9"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/mogi/dragon/obj/key",
		"file7"    : "/open/mogi/dragon/obj/key",
		"amount4"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file3"    : "/open/mon/obj/ghost-claw",
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount7"  : 1,
	]) );
	set( "owner", "bbsboss" );
	set( "build", 10700 );
	set( "light_up", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room106.c",
  "west" : "/open/clan/ou-cloud-club/room/room104",
]) );
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	setup();

	}
