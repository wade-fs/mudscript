// Room : /open/clan/ou-cloud-club/room/room54.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$大禮拜堂$NOR$" );
	set( "build", 10203 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "east" : "/open/clan/ou-cloud-club/room/room49",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
前方是一座長直的朝聖階梯,每二十階便會有一名手持鋼盾
以及利劍的亡靈騎士把守,要阻止任何人前進,也許他們把守的
就是另一個世界的信仰之源吧!!你可以感覺到強烈的宗教氣息
,卻無法確認其根源本質究竟為神聖或者邪惡.
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
