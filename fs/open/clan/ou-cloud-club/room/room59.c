// Room : /open/clan/ou-cloud-club/room/room59.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$時計ソ廊$NOR$" );
	set( "build", 10004 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room60.c",
  "west" : "/open/clan/ou-cloud-club/room/room58",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
所有時鐘同時發出滴.答.滴.答的聲音,不過即使這些時鐘雕飾
再怎精美,一直處在這種規律的聲音之中,總會不知不覺就讓所有的
行為隨著滴答聲起舞,終致狂舞不休而死,這可是會令人發瘋的,還
是趕快加緊腳步,離開這個魔因穿腦的詭異空間吧!!

LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
