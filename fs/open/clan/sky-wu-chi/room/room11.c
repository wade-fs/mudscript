// Room : /open/clan/sky-wu-chi/room/room11.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
這裡是休閒區，剛好來到這裡看歌星表演，現
在在台上的是恰克與。。。飛鳥怎又不見了？算了
，那我們請媚兒來客串一下吧，不過媚兒小妞，請
不要跳鋼管舞，這邊有兒童勿宜外加十八禁。。。
節目也到了尾聲了，回家的時候快到了。大家上車
往下站去吧。
LONG);
	set( "exits", ([ /* sizeof() == 4 */
		"north"     : "/open/clan/sky-wu-chi/room/room12.c",
		"south"     : "/open/clan/sky-wu-chi/room/room10.c",
		"east"      : "/open/clan/sky-wu-chi/room/room22.c",
]) );
	set( "short", "走 廊 4" );
	set( "build", 76 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	setup();

	}
