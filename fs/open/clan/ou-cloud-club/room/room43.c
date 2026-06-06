// Room : /open/clan/ou-cloud-club/room/room43.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "古老密道" );
	set( "owner", "snowy" );
	set( "object", ([
		"amount4"  : 1,
		"file6"    : "/open/ping/questsfan/obj/diamond_hands",
		"amount8"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_cloak",
		"file7"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount6"  : 1,
		"file8"    : "/open/ping/questsfan/obj/diamond_armor",
		"amount5"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/ping/questsfan/obj/stone",
		"amount2"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_legging",
		"file4"    : "/open/ping/questsfan/obj/diamond_boots",
		"amount1"  : 1,
		"file5"    : "/open/ping/questsfan/obj/diamond_skirt",
		"amount3"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 10033 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
一條樓梯在此蜿蜒而上,不知通往何方,不過你稍微可以見到牆外的
明亮月光了,大得有如近看車輪,卻又完美無瑕疵的月亮,雖然美麗,但在
幾許垂下樹枝的飄逸襯托之下,卻更令人覺得毛骨悚然,月,可以是件藝術
但也伴隨著黑暗而來臨,好比,這座妖氣瀰漫的華麗古堡.
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"pass"      : "/open/clan/ou-cloud-club/room/room771",
		"west"      : "/open/clan/ou-cloud-club/room/room45.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
