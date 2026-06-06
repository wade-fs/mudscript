// Room : /open/clan/ou-cloud-club/room/room102.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
你一口氣潛了大概十數公尺深,居然在一面牆上發現一道老
舊的木門,這道門的存在著實令人費解,難道在這片水域之下竟
有著具思考力的生命居住著嗎??然而門後傳來的壓迫感卻又令
人感到陣陣的不安,或許在破門的同時,就是生命失去的瞬間..
LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "short", "$HIW$惡魔城$HIR$地下水脈$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room103",
	]) );
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	setup();

	}
