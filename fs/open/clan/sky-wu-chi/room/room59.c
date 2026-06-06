// Room : /open/clan/sky-wu-chi/room/room59.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/sky-wu-chi/room/room4",
]) );
	set( "light_up", 1 );
	set( "short", "$HIY$寒風山莊$NOR$--$HIG$綠蔭大道$NOR$" );
	set( "long", @LONG
寂靜的走道，兩旁懸掛著明亮的燈火，右方似乎有著些
許光線，也許快到天道無極的天極殿了，溫暖的火光照著自
己覺得格外的舒適，想不到看似冷寂的外表，竟有如此陽光
的一面，正一邊享受這美好的一片時，感覺似乎好像快走到
了。
LONG);
	set( "no_transmit", 1 );
	set( "clan_room", "天道無極" );
	set( "no_clean_up", 0 );
	setup();

	}
