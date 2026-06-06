// Room : /open/clan/sky-wu-chi/room/room74.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIM$【小佩的小小窩】$NOR$" );
	set( "owner", "peiyi" );
	set( "object", ([
		"amount2"  : 1,
		"file9"    : "/open/scholar/obj/icefan",
		"amount6"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/mogi/dragon/obj/key",
		"file3"    : "/open/capital/room/king/obj/dagger1",
		"amount10" : 1,
		"amount5"  : 1,
		"file2"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/capital/obj/king-ring",
		"file6"    : "/open/capital/obj/king-boots",
		"amount7"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/capital/obj/king-belt",
		"amount1"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/capital/obj/king-cloak",
		"file5"    : "/open/capital/obj/king-cloth",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 11523 );
	set( "long", @LONG
這裡是小佩佩棲身的住所，進門左手邊有一個小小的置物櫃，裡面放著小佩佩
的小小鞋。繞過一個小小的屏風，後面是小佩佩生活起居的小小地方，在這個小小
地方裡，有一張小小床跟一個小小梳妝檯。在粉紅小小床的旁邊是小佩佩的小小衣
物櫃，裡面放著小小的衣服。在小小床跟小小屏風中間的小小空地，是小佩佩常常
練習跳舞的小小地方。
LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
		"north"     : "/open/clan/sky-wu-chi/room/room226.c",
		"south"     : "/open/clan/sky-wu-chi/room/room285.c",
		"east"      : "/open/clan/sky-wu-chi/room/room309",
		"out"       : "/open/clan/sky-wu-chi/room/room23.c",
]) );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	setup();

	}
