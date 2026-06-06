// Room : /open/clan/ou-cloud-club/room/room65.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$大競技場$NOR$" );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "east" : "/open/clan/ou-cloud-club/room/room64",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
焦黃的的地板,嚴重剝落以及具有刻鑿痕跡的石壁,顯示
這裡是上古時期格鬥擊技比賽的使用場遺跡,或許德古拉在
他永世不朽的生命中,亦嚐試磨練武技?或者僅僅作為觀賞
戰士生死相搏的娛樂場所!?先不論這點,你已見到面前有不少
骷髏戰士正全副武裝,聚精會神的比畫著,對於你的到來,似乎
完全沒有注意到...
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
