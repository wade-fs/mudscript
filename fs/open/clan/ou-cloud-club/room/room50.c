// Room : /open/clan/ou-cloud-club/room/room50.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$鍊金研究棟$NOR$" );
	set( "build", 10018 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room51.c",
  "west" : "/open/clan/ou-cloud-club/room/room48",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
狹長的華麗走廊,因為這裡研究的是中世紀的冶金技術,
所以隨處可見各種金碧輝煌的藝術極品,甚至連地板都是鍍上
一層金之後,再鋪上一張張炫麗名貴的波斯地毯,桌上擺設的,
是銀製餐具以及閃爍著五彩亮光的燭臺,世界上除了皇宮之外
,大概再也找不到如此漂亮尊貴的的地方了.
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
