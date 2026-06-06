// Room : /open/clan/sky-wu-chi/room/room12.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "走 廊 5" );
	set( "cmkroom", 1 );
	set( "long", @LONG
回家的路總是慢長的，今天的收獲真是相當
的多，不但看到了許多的動物，回程時還有馬疑
慈表演孫叔叔說：乖孩子，夜深了，快回家吧。
也看到了「零」所帶來精采的對抗冰判官密技，
就是全部都回答零，包你睡到飽。真是不虛此行
啊。
LONG);
	set( "exits", ([ /* sizeof() == 5 */
		"east"      : "/open/clan/sky-wu-chi/room/room23.c",
		"south"     : "/open/clan/sky-wu-chi/room/room11.c",
]) );
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "clan_room", "天道無極" );
	set( "light_up", 1 );
	setup();

	}
