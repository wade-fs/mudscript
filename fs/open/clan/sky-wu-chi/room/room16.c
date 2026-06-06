// Room : /open/clan/sky-wu-chi/room/room16.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	set( "long", @LONG
     你進入了恨天的房間，房內擺設非常的簡單，只有小小的幾張椅子，
 幾張木桌，和一張小小的床，你不斷的環顧四周，愈看愈覺得舒適且高雅
 ，你注意到了牆邊的一塊石頭，上面刻著「絕世刀客」，一股刀客的刀氣
 充滿了整個房間，空氣中充滿了殺氣，你似乎隨時有生命的危險。
. 
LONG);
	set( "short", "刀絕無情" );
	set( "owner", "roboo" );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room185",
		"east"      : "/open/clan/sky-wu-chi/room/room206.c",
	]) );
	set( "build", 10078 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
