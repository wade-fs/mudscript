inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("龍之岩",({"board"}));
	set("long","聖域內所有的大小事情都公佈在這粒大岩之上");
	set("board_id","dragon-world");
	set("capacity",50);
	set("make_clan","dragon-world");
	set("location","/open/clan/dragon-world/room/hall");
	setup();
}
