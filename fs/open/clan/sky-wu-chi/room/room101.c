// Room : /open/clan/sky-wu-chi/room/room101.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "九曲蛇道" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "long", @LONG
 你來到了聞名的九曲蛇道，放眼望去，這兒果真如
其名般的九彎十八拐。不僅如此，通道的寬度一次僅可
容納一人通過而已....所以..你得小心 防止前面的敵人衝過來
如此你就毫無進退之路了...........小心.~~~~~~喔..
LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
		"north"     : "/open/clan/sky-wu-chi/room/room119",
		"south"     : "/open/clan/sky-wu-chi/room/room102.c",
]) );
	set( "cmkroom", 1 );
	setup();

	}
