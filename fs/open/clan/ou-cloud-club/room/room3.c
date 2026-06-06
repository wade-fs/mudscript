// Room : /open/clan/ou-cloud-club/room/room3.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "神秘實驗室" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount9"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount10" : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-boots",
	]) );
	set( "owner", "snowy" );
	set( "build", 10161 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 3 */
		"east"      : "/open/clan/ou-cloud-club/room/room45.c",
		"west"      : "/open/clan/ou-cloud-club/room/room28.c",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
你似乎聽見附近傳來一陣一陣不協調的傳來機械運轉聲,
在這座擁有悠久歷史的古堡之中尤其顯得突兀,或許是德古拉
厭倦了一直使用魔法的日子,而想以機械取代魔力的消耗吧!!
否則又怎會有金屬研究以及機些裝置的存在呢!?

LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
