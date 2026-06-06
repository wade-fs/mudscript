// Room : /open/clan/ou-cloud-club/room/room61.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$時計ソ廊$NOR$" );
	set( "build", 2250 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "westup" : "/open/clan/ou-cloud-club/room/room64.c",
  "eastdown" : "/open/clan/ou-cloud-club/room/room57",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
你攀登上來之後,前面是一連串陡峭的的斜坡,斜坡兩側竟
各站立著一個手持迴旋鏢的骷髏頭,真是令人觸目心驚,而當它
們見到你之後,原本僵凝住的關節突然動了起來,握著迴旋鏢的
手高高舉起,眼看著就要擲出,將你當場擊殺,戰或逃...?

LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
