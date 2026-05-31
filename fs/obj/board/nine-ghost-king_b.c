inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("[21m期待九天回來[0m",({"board"}));
	set("long","滅幫後臨時公佈欄");
	set("board_id","nine-ghost-king");
	set("make_clan","nine-ghost-king");
	set("capacity",25);
	set("location","/open/clan/nine-ghost-king/room/hall");
	setup();
}
