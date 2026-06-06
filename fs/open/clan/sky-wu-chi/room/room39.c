// Room : /open/clan/sky-wu-chi/room/room39.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "clan_room", "天道無極" );
	set( "long", @LONG
這裡是天道無極幫下幫眾所休息，閒聊的場所，
要是你覺得累了,可以在此地稍做休息,與人聊一聊天
,大家都會很歡迎你的.不論你是新幫眾或是老一輩的
玩家，在此休息絕對是你最佳的選擇。除了休息。往
上也是通往幫中人員房間的道路。

LONG);
	set( "short", "天蘿密林" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/sky-wu-chi/room/room38",
]) );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	setup();

	}
