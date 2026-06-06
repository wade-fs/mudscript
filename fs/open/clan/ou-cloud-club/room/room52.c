// Room : /open/clan/ou-cloud-club/room/room52.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$鍊金研究棟$NOR$" );
	set( "build", 10021 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "down" : "/open/clan/ou-cloud-club/room/room53.c",
  "up" : "/open/clan/ou-cloud-club/room/room51",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
意外的發現這是個會自動升降的小平台,公用類似於現今
的電梯,看來即使擁有強大力量,這裡的主人也不願意放棄一些
為懶惰而發明的設計呢!只不過尚未完全現代化的技術使得這平
台看起來只像是一個建築工地使用的運輸貨架.
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
