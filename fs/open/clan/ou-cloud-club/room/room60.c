// Room : /open/clan/ou-cloud-club/room/room60.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$時計ソ廊$NOR$" );
	set( "build", 10046 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
		"down"      : "/open/clan/ou-cloud-club/room/room41",
		"west"      : "/open/clan/ou-cloud-club/room/room59.c",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
充滿時鐘的奇異走廊,而這裡似乎就是它的盡頭,仔細看一下這條
走廊,身處其中,似乎特別能感到時間的流動,或許在這走廊中隱藏著
什麼重大的秘密,不過,更令人驚訝及佩服的,還是當初構築完成這走廊
的創始者吧,縱使無法了解他創造的動機為何,也能對這賦予空間時光
感覺的作品感到詐舌
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
