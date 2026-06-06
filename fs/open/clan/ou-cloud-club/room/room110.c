// Room : /open/clan/ou-cloud-club/room/room110.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
這裡的水深長達五六公尺,再往後的深度恐怕有過之而無
不及,看來只能以游泳的方式前進了,在這種不知道水面下有
什麼生物的情況下游泳而過,真是令人膽戰心驚啊,不過大家
心知肚明,既然武功高強,唯一會令你煩惱的,只不過是會弄濕
身上的華麗衣飾吧 :p
LONG);
	set( "cmkroom", 1 );
	set( "short", "$HIR$惡魔城$HIW$地下水脈$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/obj/lin-cloud-fan",
		"amount1"  : 1,
		"file9"    : "/open/ping/obj/cloud_fan",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount3"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount5"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/doctor/pill/human_pill",
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount8"  : 1,
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount7"  : 43,
	]) );
	set( "build", 11112 );
	set( "light_up", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room111.c",
  "west" : "/open/clan/ou-cloud-club/room/room106",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
