// Room : /open/clan/sky-wu-chi/room/room46.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "long", @LONG
幕前的就是天道無極所最中心的天極殿，此乃是
天道無極之幫眾所齊心合力所完成的地方，雖沒有那
華麗裝飾品，也沒那氣派的名家詩畫，卻有那無比的
高貴感，只重感覺不重外表的幫眾，以將那殿堂視為
所最重視的地方了
LONG);
	set( "exits", ([ /* sizeof() == 2 */
		"north"     : "/open/clan/sky-wu-chi/room/room158.c",
		"west"      : "/open/clan/sky-wu-chi/room/room154.c",
]) );
	set( "short", "殿前大道" );
	set( "owner", "cong" );
	set( "cmkroom", 1 );
	setup();

	}










































































