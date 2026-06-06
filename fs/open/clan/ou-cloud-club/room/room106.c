// Room : /open/clan/ou-cloud-club/room/room106.c
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
	set( "clan_room", "傲雲山莊" );
	set( "short", "$HIW$惡魔城$HIR$地下水脈$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount5"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount9"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount6"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-pants",
	]) );
	set( "owner", "bbsboss" );
	set( "light_up", 1 );
	set( "build", 10894 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room110.c",
  "west" : "/open/clan/ou-cloud-club/room/room105",
]) );
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	setup();

	}
