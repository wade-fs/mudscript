// Room : /open/clan/sky-wu-chi/room/room21.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "exits", ([ /* sizeof() == 2 */
		"north"     : "/open/clan/sky-wu-chi/room/room315.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room41.c",
		"west"      : "/open/clan/sky-wu-chi/room/room10.c",
		"up"        : "/open/clan/sky-wu-chi/room/room72.c",
		"down"      : "/open/clan/sky-wu-chi/room/room363.c",
]) );
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	set( "long", @LONG
{嗯? 虎王在哪裡? 我怎麼都沒看到?}
遊客甲向旁邊略胖的遊客乙喃喃抱怨道.
{叉路這麼多,我們就都走走吧!}
{這管路的到底在幹什麼?}
忽然 $HIW$思量$NOR$跳出來一口咬住遊客甲,一腳踩住遊客乙
{格老子,我寫的區域還敢囉嗦}
話聲一完,一陣清風吹過,這邊又是條靜謐的小徑.
LONG);
	set( "short", "$HIY$神秘叉路$NOR$" );
	set( "build", 25 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
