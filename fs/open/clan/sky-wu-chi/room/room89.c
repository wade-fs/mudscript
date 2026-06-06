// Room : /open/clan/sky-wu-chi/room/room89.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "火極殿" );
	set( "light_up", 1 );
	set( "owner", "shih" );
	set( "long", @LONG
炎之殿堂，火極殿，幟熱的環境下，擁有著人世間
不可捉摸之物，幻化之火，炎之龍岩，遍佈著整個火極
殿堂，其獨特之炎之龍岩和幻化之火，是自古就以停駐
在此，使人對於天道無極之五行殿更加充滿了想對它多
加了解的念頭。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "west" : "/open/clan/sky-wu-chi/room/room87",
]) );
	set( "cmkroom", 1 );
	setup();

	}
