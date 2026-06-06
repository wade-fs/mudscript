// Room : /open/clan/sky-wu-chi/room/room7.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
寒風山莊，看似清寒極冷，實際上卻是一個鳥語花香的別墅
沒有那冬寒，又哪來的別樹一格的獨特溫馨，這裡不但沒有那刺
骨的寒風，也沒那擾耳的風戾聲，只那寒若冰的外觀下，有著大
家喜悅的歡笑聲，以及那人情似暖的友情下，共同建立的大家庭
而以。

LONG);
	set( "exits", ([ /* sizeof() == 2 */
		"down"      : "/open/clan/sky-wu-chi/room/room5",
		"enter"     : "/open/clan/sky-wu-chi/room/room8.c",
]) );
	set( "short", "$HIY$寒風山莊$NOR$" );
	set( "build", 79 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	setup();

	}
