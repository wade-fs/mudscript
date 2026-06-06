// Room : /open/clan/ou-cloud-club/room/room42.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$入口$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"amount8"  : 1,
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 14826 );
	set( "light_up", 1 );
	set( "long", @LONG
空氣中飄來一古潮濕的氣息,你正站在一個懸空平台上,下方是深不見
底的水道,水裡有為數不少的醜陋人魚,不時跳上水面口吐火焰的向你挑釁
,但似乎無法離開水面太久,所以馬上又鑽回水裡了,水面下似乎另有洞天,
然上方飛來的蝙蝠也令人相對的產生好奇,或許上面是比較接近邪惡之源
的地方呢!!
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 3 */
		"down"      : "/open/clan/ou-cloud-club/room/room44.c",
		"west"      : "/open/clan/ou-cloud-club/room/room41.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
