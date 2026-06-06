// Room : /open/clan/sky-wu-chi/room/room32.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "clan_room", "天道無極" );
	set( "long", @LONG
房內擺著$HIG$烏木有束腰鼓腿彭牙梅花凳$NOR$,
            $HIR$紅木六開光雕拐子龍紋鼓墩$NOR$,
            $HIW$黑白萬花嵌螺鈿酸枝木小圓桌$NOR$,
雖說$HIW$思量$NOR$只是個小小副幫主,
這房內的擺置簡直可比帝王之家的還享受,
一陣腳步聲急行而來,
是誰,竟然沒經思量同意逕行闖入,
原來是老大$HIC$燕仔$NOR$,
燕仔一看房內,被屋內閃閃發亮的家俱刺的張不開眼,
呆了半餉,終於回過神來喝道{哇咧!幫款被你盜用多少? *_*}
LONG);
	set( "short", "碎石小路 1111" );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"north"     : "/open/clan/sky-wu-chi/room/hall.c",
		"south"     : "/open/clan/sky-wu-chi/room/room175",
]) );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	setup();

	}
