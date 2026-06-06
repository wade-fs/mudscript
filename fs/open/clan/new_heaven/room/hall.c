// Room : /open/clan/new_heaven/room/hall.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "天堂大門口" );
	set( "objects", ([ /* sizeof() == 3 */
  "/u/b/bss/train2" : 1,
]) );
	set( "exits", ([ /* sizeof() == 2 */
  "west" : "/open/clan/new_heaven/room/room5.c",
  "north" : "/open/clan/new_heaven/room/room2.c",
]) );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是新天堂的大門口, 這裡應該只有巫師才可以進得來,
主要是給巫師們有個測試幫派的地方
LONG);
	set( "no_clean_up", 0 );
	setup();

	}
