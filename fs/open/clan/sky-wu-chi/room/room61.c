// Room : /open/clan/sky-wu-chi/room/room61.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
廚房裡亂成一團，十幾個人追著一條豬跑，而這裡的主廚莫古里在一旁監督著
其他廚師，一邊調教新廚師一邊發明新的菜色，並將深宮奇毒，五毒，火玫瑰毒跟
一刻香分別做出一道道美味的料理，並主張用愛與和平來做料理。
LONG);
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "short", "Rue專用廚房" );
	set( "build", 495 );
	set( "owner", "rue" );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room308",
	]) );
	set( "no_transmit", 1 );
	set( "clan_room", "天道無極" );
	set( "cmkroom", 1 );
	setup();

	}
