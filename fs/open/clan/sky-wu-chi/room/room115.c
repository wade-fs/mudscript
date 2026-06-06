// Room : /open/clan/sky-wu-chi/room/room115.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "cmkroom", 1 );
	set( "long", @LONG
這兒是天道無極的陣眼，陣眼中設有八八六十四卦，分
別通往不同的卦象讓幫眾能從這兒到達其它幫眾的練功房，
也能從這兒回到幫內大廳，這個房間沒有什麼擺設，只有在
中心有一個高八尺、寬八尺，呈八角型狀的鐵鑄大八卦，上
頭以朱漆繪有易經上的六十四個卦象。

LONG);
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 3 */
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room316",
]) );
	set( "short", "乾坤門" );
	set( "owner", "crlin" );
	set( "object", ([
		"file5"    : "/open/doctor/pill/ice_pill",
		"file10"   : "/open/doctor/item/sick_item",
		"amount3"  : 901,
		"file8"    : "/obj/gift/xisuidan",
		"amount9"  : 1230,
		"file6"    : "/open/doctor/pill/sky_pill",
		"amount10" : 1204,
		"amount6"  : 2453,
		"amount8"  : 1,
		"file9"    : "/open/doctor/pill/ff_pill",
		"file1"    : "/open/doctor/pill/taii_pill",
		"amount1"  : 656,
		"amount5"  : 524,
		"file2"    : "/open/doctor/obj/needle9",
		"amount2"  : 1,
		"file3"    : "/open/doctor/pill/nine_pill",
	]) );
	set( "light_up", 1 );
	set( "build", 10004 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	setup();

	}
