// Room : /open/clan/sky-wu-chi/room/room81.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "地極殿" );
	set( "light_up", 1 );
	set( "long", @LONG
「地極殿」此乃天道無極之五極殿堂之一，樸素的殿
堂下，更顯得出他的高貴。天道五行，幻化無窮，但最讓
人明瞭的也只有像地極那樣的。雖然這沒有像那天極殿樣
般的華麗，只是一個偏廳，但從此殿的設計與位置來看，
似乎是有什麼隱藏的力量。在廳旁的柱子(sign)上，似乎
有刻著什麼樣的字在上面。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "north" : "/open/clan/sky-wu-chi/room/room92.c",
  "east" : "/open/clan/sky-wu-chi/room/room80",
]) );
	set( "cmkroom", 1 );
	set( "item_desc", ([ /* sizeof() == 1 */
  "sign" : "
天道無極之五行幻化，變化莫測。

",
]) );
	setup();

	}
