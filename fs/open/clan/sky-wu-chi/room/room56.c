// Room : /open/clan/sky-wu-chi/room/room56.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "short", "測試連結區" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room25.c",
		"west"      : "/open/clan/sky-wu-chi/room/room66.c",
	]) );
	set( "long", @LONG
這裡是天道無極的新生宿舍,別以為他們都是小小的肉腳喔
他們可是有單挑sa;fire king 的能力喔,平時這裡常常傳出了
苦練的聲音,他們的目標只有一個,打倒 刀神燕仔~~~~~~~~
所以..走到這裡使你不禁興起了尊敬之心,對於這新生宿舍
在也不敢輕視....
LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "cmkroom", 1 );
	setup();

	}
