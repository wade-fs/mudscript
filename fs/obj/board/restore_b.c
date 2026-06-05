
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
	set_name( HIR + "枉死簿" + NOR, ({ "unjust death book", "board" }) );
	set( "location", "/open/wiz/restore" );
	set( "board_id", "restore_b" );
	set( "long", "若因 bug 而枉死者, 可以來此 post 請求 restore" );
	setup();
	set( "capacity", 300 );
}
