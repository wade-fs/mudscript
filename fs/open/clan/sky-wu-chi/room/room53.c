// Room : /open/clan/sky-wu-chi/room/room53.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "short", "$HIY$寒風山莊$HIW$--$HIG$綠蔭大道$NOR$" );
	set( "long", @LONG
當你清幽的行走於$HIY$寒風山莊$NOR$時，一陣刀氣呼蕭而過，你被這突乎
其來的刀氣嚇的膽戰心驚，抬頭一看，一個匾額寫著$HIW$【$HIC$神谷活心流$HIW$】$NOR$
，原來你走到了由緋村劍心與神谷薰所指導的道館，看到此刀氣如此
的銳利，看來揮刀者的功力不斐。
LONG);
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"north"     : "/open/clan/sky-wu-chi/room/room8",
]) );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "cmkroom", 1 );
	setup();

	}
