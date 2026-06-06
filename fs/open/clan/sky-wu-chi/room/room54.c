// Room : /open/clan/sky-wu-chi/room/room54.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "short", "寒風山莊--綠蔭大道" );
set( "long", @LONG
你來到了$HIW$【$HIC$神谷活心流$HIW$】$NOR$道館的大門口處，陣陣刀風呼蕭而過，
所幸你本身的功力也不淺薄，閃躲突乎其來的刀氣尚不算難事一件，
不過，如果當面與揮刀者對決，或許勝算還有待考量，你呆望著斑黃
的道館門牌，可以稍微體會到這道館已經與$HIY$寒風山莊$NOR$並存了好一陣子
了，道館的週遭也是由木板所圍繞而成的。
LONG);
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"enter"     : "/open/clan/sky-wu-chi/room/room55.c",
		"north"     : "/open/clan/sky-wu-chi/room/room53.c",
]) );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "cmkroom", 1 );
	setup();

	}
