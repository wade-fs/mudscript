// Room : /open/clan/ou-cloud-club/room/room44.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "傲雲山莊" );
	set( "short", "$HIW$惡魔城$HIR$地下水脈$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"amount5"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/prayer/obj/boris-cloth",
		"file1"    : "/open/prayer/obj/boris-cloth",
		"file6"    : "/open/prayer/obj/boris-cloth",
		"file2"    : "/open/prayer/obj/boris-cloth",
		"amount1"  : 1,
		"file7"    : "/open/prayer/obj/boris-cloth",
		"amount10" : 1,
		"file5"    : "/open/prayer/obj/boris-cloth",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/prayer/obj/boris-cloth",
		"file8"    : "/open/prayer/obj/boris-cloth",
	]) );
	set( "build", 10044 );
	set( "light_up", 1 );
	set( "long", @LONG
一古清涼的氣息振奮了你的精神,瞬間趕走了古堡裡沉悶的
腐敗空氣,這裡就是地下水脈了,應該也是整座城堡的供水中樞
吧,水質清澈寒冽,而且有些地方甚至是深潭,若要仔細調查此處
的隱藏秘密,下水一游似乎是免不了的了.
LONG);
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room98.c",
  "up" : "/open/clan/ou-cloud-club/room/room42",
]) );
	set( "no_transmit", 1 );
	setup();

	}
