// Room : /open/clan/ou-cloud-club/room/room111.c
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
		"amount1"  : 12,
		"amount3"  : 112,
		"file6"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount5"  : 1,
		"file2"    : "/open/doctor/pill/ice_pill",
		"file7"    : "/open/gblade/obj/sa-head",
		"file5"    : "/open/magic-manor/obj/soil-ball",
		"amount4"  : 10,
		"amount7"  : 1,
		"amount6"  : 7,
		"file3"    : "/open/doctor/pill/gnd_pill",
		"amount2"  : 16,
		"amount9"  : 1,
		"file9"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file10"   : "/open/mon/obj/flower-claw",
		"file4"    : "/open/mogi/castle/obj/blood-water",
		"amount10" : 1,
		"file1"    : "/open/doctor/pill/sky_pill",
	]) );
	set( "light_up", 1 );
	set( "build", 10015 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room112.c",
  "west" : "/open/clan/ou-cloud-club/room/room110",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
