// Room : /open/clan/ou-cloud-club/room/room53.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$鍊金研究棟$NOR$" );
	set( "build", 10815 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "down" : "/open/clan/ou-cloud-club/room/room19",
  "up" : "/open/clan/ou-cloud-club/room/room52",
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
