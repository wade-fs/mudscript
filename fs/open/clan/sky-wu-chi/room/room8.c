// Room : /open/clan/sky-wu-chi/room/room8.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "long", @LONG
華麗的外表下，寒風山莊卻有著一種不為
人知的內幕，其實裡面盡然是幫眾的宿舍，首
先看到的是左手邊的是小新的宿舍，小心，別
亂丟垃圾喔，再來看到的是，右手邊的軒轅賤
俠小老哥的鳥窩。小心別把頭伸出去喔。。。
接下來看的是五福村動物園的夜行動物區，來
來來，繼續往前走。。。

LONG);
	set( "exits", ([ /* sizeof() == 6 */
		"north"     : "/open/clan/sky-wu-chi/room/room9.c",
		"west"      : "/open/clan/sky-wu-chi/room/room14.c",
		"out"       : "/open/clan/sky-wu-chi/room/room7.c",
]) );
	set( "short", "走 廊 1" );
	set( "build", 47 );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "cmkroom", 1 );
	setup();

	}
