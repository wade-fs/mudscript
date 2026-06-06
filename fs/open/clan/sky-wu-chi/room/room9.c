// Room : /open/clan/sky-wu-chi/room/room9.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
接下來看到的是夜行動物區，在我們左
手邊的是有死亡之稱的是「蝙蝠」死亡人生
，小弟弟，請不要把手放到窗外喔。。。再
來，我們看到的是。。。唉呀，小心不要讓
「攘袂生」跑到車上來喔，來我們接下來去
下一區吧。
LONG);
	set( "exits", ([ /* sizeof() == 4 */
		"west"      : "/open/clan/sky-wu-chi/room/room15.c",
		"east"      : "/open/clan/sky-wu-chi/room/room20.c",
		"south"     : "/open/clan/sky-wu-chi/room/room8.c",
]) );
	set( "short", "走 廊 2" );
	set( "build", 977 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	setup();

	}
